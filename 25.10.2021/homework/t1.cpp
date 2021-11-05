//Определите очередной год, в который заданное число будет приходиться на пятницу.
#include <iostream>

using namespace std;

int main()
{
    int day, mon;
    cin>>day>>mon;
    int a = (14 - mon)/12;
    int m = mon + 12*a - 2;
    int y = 2021 - a;
    while ((day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7 != 5){
        y++;
    }
    cout << y + a;
    return 0;
}
