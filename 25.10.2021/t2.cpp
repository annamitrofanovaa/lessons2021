#include <iostream>

using namespace std;

int main()
{
    int day, mon, year;
    cin >> day >> mon >> year;
    int a = (14 - mon) / 12;
    int y = year - a;
    int m = mon + 12 * a - 2;
    int res = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
    switch (res)
    {
        case 0:
            cout << "sunday";
            break;
        case 1:
            cout << "monday";
            break;
        case 2:
            cout << "thursday";
            break;
        case 3:
            cout << "wednesday";
            break;
        case 4:
            cout << "thursday";
            break;
        case 5:
            cout << "friday";
            break;
        case 6:
            cout << "saturday";
            break;
    }
    
    return 0;
}