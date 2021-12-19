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
    int count = 0, denominator = 1;
    double acc, pi = 0;

    std::cin >> acc;
    do
    {
        if (count % 2 == 0)
        {
            pi += double(4. / denominator);
        }
        else
        {
            pi -= double(4. / denominator);
        }
        denominator += 2;
        ++count;
    } while (std::fabs(pi - M_PI) >= acc);
    std::cout << pi << ' ' << count << '\n';

    return 0;
}