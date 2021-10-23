/*
Точки в окружности. Дана окружность с целочисленным радиусом R<10^6. 
Посчитать число точек с целочисленными координатами, лежащих внутри окружности,
 в том числе и находящихся на границе окружности.
*/
#include <iostream>

using namespace std;

int main()
{
    float x = -1.5;
    float y = 1.5;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            if ((x * x * x + y * y - 1) * (x * x * x + y * y - 1) * (x * x * x + y * y - 1) - x * x * y * y * y <= 0)
            {
                cout << "*";
            }
            else
            {
                cout << ".";
            }
            x = x + 0.075;
        } 
        y = y - 0.15;
        x = -1.5;
        cout << endl;
    }

    return 0;
}