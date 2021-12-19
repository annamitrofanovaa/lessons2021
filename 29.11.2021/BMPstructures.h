#pragma once
#include <cstdint>

// typedef unsigned short WORD; // 2 байта, беззнаковое
typedef std::uint16_t WORD;
// typedef unsigned int DWORD;  // 4 байта, беззнаковое
typedef std::uint32_t DWORD;
typedef int LONG;
typedef unsigned char BYTE; // 1 байт, беззнаковое

#pragma pack(push, 1)
struct BITMAPFILEHEADER
{
	WORD bfType;
	DWORD bfSize; // размер файла
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits; // смещение до поля данных (обычно 54 = 16+biSize)
};

struct BITMAPINFOHEADER
{
	DWORD biSize; // размер структуры в байтах
	LONG biWidth; // ширина в пикселях
	LONG biHeight;
	WORD biPlanes;	 // Всегда должно быть 1
	WORD biBitCount; // Кол-во бит на цвет 0 | 1 | 4 | 8 | 16 | 24 | 32
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter; // горизонтальное разрешение
	LONG biYPelsPerMeter; // вертикальное разрешение
	DWORD biClrUsed;	  // Кол-во используемых цветов (если используется таблица цветов)
	DWORD biClrImportant; // Кол-во сущестенных цветов
};

struct RGB
{
	BYTE Blue;
	BYTE Green;
	BYTE Red;
};

struct rgbImg
{
	RGB **pixels;
	unsigned int width;
	unsigned int height;
};

#pragma pack(pop)