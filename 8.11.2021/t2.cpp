#include <iostream>
#include <vector>

using namespace std;

void shiftarray(vector<int> &arr, int shift, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i+shift];
    }
}

int main()
{
    int shift, n;
    cin >> shift >> n;
    vector<int> arr;
    arr.resize(n + shift);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = n; i < n + shift; i++)
    {
        arr[i] = arr[i - n];
    }
    
    shiftarray(arr, shift, n);
    //&arr[0] = &arr[shift];
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}