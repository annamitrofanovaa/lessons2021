#pragma once
#include <utility>
#include "BMPstructures.h"

int get_offset(int width);
rgbImg read_rgb_bitmap(const char filename[]);
void write_rgb_bitmap(const char filename[], const rgbImg &img);
void delete_img(rgbImg &img);
void img_rot180(rgbImg &img);

void img_rot90(rgbImg &img);

template <typename T>
void reverse_array(T *A, size_t Len)
{
    if (Len > 0)
        for (size_t i = 0, j = Len - 1; i < j; ++i, --j)
        {
            std::swap(A[i], A[j]);
        }
}