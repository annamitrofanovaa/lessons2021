/*
Написать программу, которая вычисляет число pi с заданной
пользователем точностью. Для вычисления значения числа pi воспользоваться формулой: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)

Определить какое количество дробей необходимо было добавить
к сумме, чтобы обеспечить заданную точность. Запомнить кол-во, например в переменной N.

*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

int main()
{
    int n = 0, denominator = 1;
    double acc, pi = 0;

    std::cin >> acc;
    do
    {
        if (n % 2 == 0)
        {
            pi += double(4. / denominator);
        }
        else
        {
            pi -= double(4. / denominator);
        }
        denominator += 2;
        ++n;
    } while (std::fabs(pi - M_PI) >= acc);
    std::cout << "pi_1 = " << pi << " n = " << n << '\n';

    int R, count = 0;
    std::cout<<"radius=";
    std::cin >> R;

    for (int i = 0; i < n; ++i)
    {
        int x = rand() % R;
        int y = rand() % R;
        int point_radius = x * x + y * y;
        if (point_radius <= R * R)
        {
            count++;
        }
    }
    std::cout <<"pi_2 = "<<4.0 * (double)count / (double)n;

    return 0;
}