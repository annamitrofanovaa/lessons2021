//Какова вероятность того, что 13 число заданного месяца окажется пятницей? Определите количество пятниц, пришедшихся на 13-е числа в XX столетии.
#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int k = 1; k <= 12; k++)
        {
            int a = (14 - k) / 12;
            int m = k + 12 * a - 2;
            int y = 1901 + i - a;
            if ((13 + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7 == 5)
            {
                count++;
            }
        }
    }
    float p = count /5214.;
    cout<<count<<"  ver = "<<(float)p;
    return 0;
}
