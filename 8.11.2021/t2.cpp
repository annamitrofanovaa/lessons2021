#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    if (b % a == 0)
    {
        return a;
    }
    if (a > b)
    {
        return gcd(a % b, b);
    }
    return gcd(a, b % a);
}

int main()
{
    int shift, n;
    cout << "shift:";
    cin >> shift;
    cout << "size:";
    cin >> n;

    if (shift < 0)
    {
        shift = n + shift;
        shift = (-1 * shift) % n;
    }
    shift %= n;

    vector<int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int temp, j, k;
    for (int i = 0; i < gcd(n, shift); i++)
    {
        temp = arr[i];
        j = i;
        while (1)
        {
            k = j + shift;
            if (k >= n)
                k -= n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}