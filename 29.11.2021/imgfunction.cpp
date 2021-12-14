#include "imgfunction.h"
#include <fstream>
#include <exception>

int get_offset(int width)
{
    int offset = 0;
    if (width % 4)
    {
        offset = 4 - (3 * width) % 4;
    }
    return offset;
}

BYTE normalize(double x)
{
    x = x > 255 ? 255 : x;
    x = x < 0 ? 0 : x;
    return (BYTE)x;
}

rgbimg read_rgb_bitmap(const char filename[])
{
    std::ifstream inBMP("pic1.bmp", std::ios_base::binary);
    if (!inBMP.is_open())
    {
        throw std::runtime_error("cant open file");
        // return 1;
    }
    BITMAPFILEHEADER bmfh;
    inBMP.read((char *)&bmfh, sizeof(BITMAPFILEHEADER));
    // std::cout << "file size" << bmfh.bfsize;
    inBMP.close();
    system("pause");

    BITMAPINFOHEADER bmih;
    inBMP.read((char *)&bmih, sizeof(BITMAPINFOHEADER));
    // std::cout << "width" << bmih.biwidth;
    // << std::endl;
    const int offset = get_offset(bmih.biwidth);
    rgbimg img;
    img.height = bmih.biheight;
    //
    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
        {
            inBMP.read((char *)&img.pixels[row][col], sizeof(RGB));
            //сдвинуться на офсет
        }
        inBMP.seekg(offset, std::ios_base::cur);
    }
    inBMP.close();
    return img;
}
void write_rgb_bitmap(const char filename[], const rgbimg &img)
{
    std::ofstream outBMP(filename, std::ios_base::binary);
    if (!outBMP.is_open())
        throw std::runtime_error("failed open");
    const int offset = get_offset(img.width);
    BITMAPFILEHEADER bmfh;
    char bfType[] = {'B', 'M'};
    bmfh.bftype = *((WORD *)bfType);
    bmfh.bfoffbits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfsize = img.height * img.width * 3 + bmfh.bfoffbits;
    bmfh.bfreserved1 = 0;
    bmfh.bfreserved2 = 0;

    outBMP.write((char *)&bmfh, sizeof(BITMAPFILEHEADER));

    BITMAPINFOHEADER bmih;
    bmih.bfsize = sizeof(BITMAPINFOHEADER); //размер структуры в байтах
    bmih.biwidth = img.width;               //ширина в пикселях
    bmih.biheight = img.height;
    bmih.biplanes = 1;    //всегда должо быть 1
    bmih.bibitcount = 24; //колво бит на цвет
    bmih.bicompression = 0;
    bmih.bisizeimage = bmfh.bfsize - bmfh.bfoffbits;
    bmih.bixpelspermeter = 1; //горизонтальное разрешение
    bmih.biypelspermeter = 1; //вертикальное разрешение
    bmih.biclrused = 0;       //колво используемых цветов
    bmih.biclrimportant = 0;
    outBMP.write((char **)&bmih, sizeof(BITMAPINFOHEADER));
}
void img_rot180(rgbimg &img)
{
    for (size_t row = 0; row < img.height; ++row)
    {
        reverse_array(img.pixels[row], img.width);
    }
    reverse_array(img.pixels, img.height);
}

void img_rot90(rgbimg &img)
{
    rgbimg tmp;
    tmp.height = img.width;
    tmp.width = img.height;
    tmp.pixels = new RGB *[tmp.height];
    for (size_t i = 0; i < tmp.height; ++i)
        tmp.pixels[i] = new RGB[tmp.width];
    for (size_t row = 0; row < img.height; ++row)
        for (size_t col = 0; col < img.width; ++col)
            tmp.pixels[img.width - col][row] = img.pixels[row][col];
    delete_img(img);
    img = tmp;
}

void img_adjust(rgbimg &img, double c, double k)
{
    for (size_t row = 0; row < img.height; row++)
    {
        for (size_t col = 0; col < img.width; col++)
        {
            img.pixels[row][col].blue = BYTE(c * img.pixels[row][col].blue + k);
            img.pixels[row][col].red = BYTE(c * img.pixels[row][col].red + k);
            img.pixels[row][col].green = BYTE(c * img.pixels[row][col].green + k);
        }
    }
}
void autolevels(rgbimg &img)
{
    RGB min = {255, 255, 255}, max = {0, 0, 0};
    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
        {
            RGB tmp = img.pixels[row][col];
            if (tmp.blue > max.blue)
                max.blue = tmp.blue;
            if (tmp.red > max.red)
                max.red = tmp.red;
            if (tmp.green > max.green)
                max.green = tmp.green;

            if (tmp.blue < min.blue)
                min.blue = tmp.blue;
            if (tmp.red < min.red)
                min.red = tmp.red;
            if (tmp.green < min.green)
                min.green = tmp.green;
            max.blue = (max.blue == min.blue) ? min.blue + 1 : max.blue;
            max.red = (max.red == min.red) ? min.red + 1 : max.red;
            max.green = (max.green == min.green) ? min.green + 1 : max.green;

            for (size_t row = 0; row < img.height; ++row)
            {
                for (size_t col = 0; col < img.width; ++col)
                {
                    RGB tmp = img.pixels[row][col];
                    img.pixels[row][col].blue = normalize((tmp.blue - min.blue) * 255 / (max.blue - min.blue));
                    img.pixels[row][col].red = normalize((tmp.red - min.red) * 255 / (max.red - min.red));
                    img.pixels[row][col].green = normalize((tmp.green - min.green) * 255 / (max.green - min.green));
                }
            }
        }
    }
}
void median(rgbimg &img, int radius){
    rgbimg source = copy_img(img);
    unsigned char* buffer = new unsigned char [(2*radius+1)*(2*radius)+1];
    //for(size_t row = )
}

void delete_img(rgbimg &img)
{
    for (size_t i = 0; i < img.height; i++)
        delete[] img.pixels[i];
    delete[] img.pixels;

    img.height = 0;
    img.width = 0;
    img.pixels = 0;
}