#pragma once
#include "bmpstr.h"

int get_offset(int width);
rgbimg read_rgb_bitmap(const char filename[]);
void delete_img(rgbimg &img);
void write_rgb_bitmap(const char filename[], const rgbimg &img);
void img_rot180(rgbimg &img);
void img_rot90(rgbimg &img);
template <typename T>

void reverse_array(T *A, size_t Len)
{
    if (Len > 0)
        for (size_t i = 0, j = Len - 1; i < j; ++i, --j)
        {
            std::swap(A[i], A[j]);
        }
}
