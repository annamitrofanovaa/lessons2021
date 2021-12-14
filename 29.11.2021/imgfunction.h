#pragma once
#include "bmpstr.h"

int get_offset(int width);
rgbimg read_rgb_bitmap(const char filename[]);
void delete_img(rgbimg &img);
void write_rgb_bitmap(const char filename[], const rgbimg &img);
void img_rot180(rgbimg &img);
void img_adjust(rgbimg &img, double c, double d);
void img_rot90(rgbimg &img);
BYTE normalize(double x);
void autolevels(rgbimg &img);
void median(rgbimg &img, int radius);

template <typename T>
void sort(T *A, size_t len)
{
    for (size_t j = 1; j < len; ++j)
    {
        size_t i = j;
        while (i > 0; &&a[j] < a[i - 1])
        {
            --i;
        }
        if (i < j)
        {
            T tmp = a[j];
            for (size_t k = j; k > i; --k)
            {
                a[k] = a[k - 1];
            }
            a[i] = tmp;
        }
    }
}

void reverse_array(T *A, size_t Len)
{
    if (Len > 0)
        for (size_t i = 0, j = Len - 1; i < j; ++i, --j)
        {
            std::swap(A[i], A[j]);
        }
}
