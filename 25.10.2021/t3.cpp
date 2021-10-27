#include <iostream>
using namespace std;
int main()
{
    const int n = 20;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 90 + 10;
    }
    for (int i = 0; i < n; ++i)
    {
        if (array[i] < 0)
        {
            cout << array[i];
        }
        else
            cout << "+" << array[i];
        cout << "x^" << n - 1 - i;
    }
     
}