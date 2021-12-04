#include <iostream>
#include <fstream>

#include "imgfunction.h"

int main()
{
    rgbimg img;
    try
    {
        img = read_rgb_bitmap("pic1.bmp");

        img_rot180(img);

        write_rgb_bitmap("result.bmp", img);
        delete_img(img);
    }
    catch (std::exception error)
    {
        std::cout << "err: " << error.what() << std::endl;
        return 1;
    }
    system("pause");
    // return 0;
}
