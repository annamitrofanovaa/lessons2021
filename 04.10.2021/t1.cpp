/* Написать программу, которая в консоли отображает m ромбов из символов звездочка '*' высоты (2n-1) звездочек. */
#include <iostream>

using namespace std;

void drawing(int r_count, int len)
{
    for (int layer = 1; layer <= len; ++layer)
    {
        for (int j = 1; j <= r_count; ++j)
        {
            for (int k = 1; k <= len - layer; ++k)
            {
                cout << ' ';
            }
            for (int k = 1; k <= 2 * layer - 1; ++k)
            {
                cout << '*';
            }
            for (int k = 1; k <= len - layer; ++k)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    for (int layer = len - 1; layer >= 1; --layer)
    {
        for (int j = 1; j <= r_count; ++j)
        {
            for (int k = 1; k <= len - layer; ++k)
            {
                cout << ' ';
            }
            for (int k = 1; k <= 2 * layer - 1; ++k)
            {
                cout << '*';
            }
            for (int k = 1; k <= len - layer; ++k)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main()
{
    int r_count, len;
    cin >> r_count >> len;
    drawing(r_count, len);
    return 0;
}
