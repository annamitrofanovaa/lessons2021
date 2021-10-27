#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2, s1, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int rh = 0, rm = 0, rs = 0;
    if (s1 < s2)
    {
        rs = rs + s2 - s1;
    }
    else
    {
        rs = rs + 60 - s1 + s2;
        rm = -1;
    }
    if (m1 < m2)
    {
        rm = rm + m2 - m1;
    }
    else
    {
        rm = rm + 60 - m1 + m2;
        rh = -1;
    }
    if (h1 < h2)
    {
        rh = rh + h2 - h1;
    }
    else
    {
        rh = rh + 24 - h1 + h2;
    }

    cout << rh << " " << rm << " " << rs;
    return 0;
}