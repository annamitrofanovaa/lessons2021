/*
У гусей и кроликов вместе 2n лап. Сколько может быть гусей и кроликов (вывести всевозможные сочетания)?
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int number;
    cin >> number;
    int count = 2 * number;
    for (int rabbits_legs = 0; rabbits_legs <= count; rabbits_legs += 4)
    {
        for (int guse_legs = 0; guse_legs <= count; guse_legs += 2)
        {
            if (rabbits_legs + guse_legs == count)
            {
                int count_of_rabbits = rabbits_legs/4;
                int count_of_guse = guse_legs/2;
                cout << "rabbits = " << count_of_rabbits << " guse_legs = " << count_of_guse << endl;
            }
        }
    }
    return 0;
}