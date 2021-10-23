/*
Для заданных значений n и x вычислить выражение: S = sin x + sin sin x + ... + sin sin ... sin x .
*/
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    int n;
    float an;
    cin >> n >> an;
    float s = 0;
    
    for (int i = 0; i < n; i++)
    {
        an = sin(an);
        s += an;
    }
    cout<<s;
    return 0;
}