#include "ImgFunctions.h"
#include <fstream>
#include <exception>

int get_offset(int width)
{
    int offset = 0;
    if (width % 4)
        offset = 4 - (3 * width) % 4;
    return offset;
}

rgbImg read_rgb_bitmap(const char filename[])
{

    std::ifstream inBMP(filename, std::ios_base::binary);
    if (!inBMP.is_open())
    {
        throw std::runtime_error("Can not open file");
    }

    BITMAPFILEHEADER bmfh;
    inBMP.read((char *)&bmfh, sizeof(BITMAPFILEHEADER));

    BITMAPINFOHEADER bmih;
    inBMP.read((char *)&bmih, sizeof(BITMAPINFOHEADER));

    const int offset = get_offset(bmih.biWidth);
    rgbImg img;
    img.height = bmih.biHeight;
    img.width = bmih.biWidth;
    img.pixels = new RGB *[img.height];
    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
            inBMP.read((char *)&img.pixels[row][col], sizeof(RGB));
        // сдвинуться на offset
        inBMP.seekg(offset, std::ios_base::cur);
    }
    inBMP.close();
    return img;
}

void delete_img(rgbImg &img)
{
    for (size_t i = 0; i < img.height; ++i)
        delete[] img.pixels[i];
    delete[] img.pixels;

    img.height = 0;
    img.width = 0;
    img.pixels = nullptr;
}

void write_rgb_bitmap(const char filename[], const rgbImg &img)
{
    std::ofstream outBMP(filename, std::ios_base::binary);
    if (!outBMP.is_open())
        throw std::runtime_error("Failed to open output file");

    const int offset = get_offset(img.width);
    BITMAPFILEHEADER bmfh;
    char bfType[] = {'B', 'M'};
    bmfh.bfType = *((WORD *)bfType);
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = img.height * img.width * 3 + bmfh.bfOffBits;
    bmfh.bfReserved1 = 0;
    bmfh.bfReserved2 = 0;

    outBMP.write((char *)&bmfh, sizeof(BITMAPFILEHEADER));

    BITMAPINFOHEADER bmih;
    bmih.biSize = sizeof(BITMAPINFOHEADER); // размер структуры в байтах
    bmih.biWidth = img.width;               // ширина в пикселях
    bmih.biHeight = img.height;
    bmih.biPlanes = 1;    // Всегда должно быть 1
    bmih.biBitCount = 24; // Кол-во бит на цвет 0 | 1 | 4 | 8 | 16 | 24 | 32
    bmih.biCompression = 0;
    bmih.biSizeImage = bmfh.bfSize - bmfh.bfOffBits;
    bmih.biXPelsPerMeter = 1;
    bmih.biYPelsPerMeter = 1;
    bmih.biClrUsed = 0;
    bmih.biClrImportant = 0;
    outBMP.write((char *)&bmih, sizeof(BITMAPINFOHEADER));

    BYTE *offset_array = new BYTE[offset];
    for (size_t i = 0; i < offset; ++i)
        offset_array[i] = 0;

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            outBMP.write((char *)&img.pixels[row][col], sizeof(RGB));
        outBMP.write((char *)offset_array, offset);
    }

    delete[] offset_array;
    outBMP.close();
}

void img_rot180(rgbImg &img)
{
    for (size_t row = 0; row < img.height; ++row)
    {
        reverse_array(img.pixels[row], img.width);
    }
    reverse_array(img.pixels, img.height);
}

void img_rot90(rgbImg &img)
{
    rgbImg tmp;

    tmp.height = img.width;
    tmp.width = img.height;
    tmp.pixels = new RGB *[tmp.height];
    for (size_t i = 0; i < tmp.height; ++i)
        tmp.pixels[i] = new RGB[tmp.width];

    for (size_t row = 0; row < img.height; ++row)
        for (size_t col = 0; col < img.width; ++col)
            tmp.pixels[img.width - 1 - col][row] = img.pixels[row][col];

    delete_img(img);
    img = tmp;
}