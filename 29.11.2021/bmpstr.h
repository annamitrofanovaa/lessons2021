#pragma once

typedef unsigned short WORD; // 2b
typedef unsigned int DWORD;  // 4b
typedef int LONG;            //
typedef unsigned char BYTE;  // 1b

#pragma pack(push, 1)
struct BITMAPFILEHEADER
{
    WORD bftype;
    DWORD bfsize; //размер файла
    WORD bfreserved1;
    WORD bfreserved2;
    DWORD bfoffbits; //смещение до поля данных(обычно 16+bfsize)
};
struct RGB
{
    BYTE blue;
    BYTE green;
    BYTE red;
};
struct BITMAPINFOHEADER
{
    DWORD bfsize; //размер структуры в байтах
    LONG biwidth; //ширина в пикселях
    LONG biheight;
    WORD biplanes;   //всегда должо быть 1
    WORD bibitcount; //колво бит на цвет
    DWORD bicompression;
    DWORD bisizeimage;
    LONG bixpelspermeter; //горизонтальное разрешение
    LONG biypelspermeter; //вертикальное разрешение
    DWORD biclrused;      //колво используемых цветов
    DWORD biclrimportant; //колво существенных цветов
};

// const int offset = get_offset(bmih.biwidth);
struct rgbimg
{
    RGB **pixels;
    unsigned int width;
    unsigned int height;
};

#pragma pack(pop)
