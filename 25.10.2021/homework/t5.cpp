/*Массив длины N в случайном порядке заполнен целыми числами
 из диапазона от 0 до N. Каждое число встречается в массиве
 не более одного раза. Найти отсутствующее число (дырку).
  Сложность алгоритма O(N). Использование дополнительной памяти, пропорциональной
  длине массива, не допускается.

А что если две дырки будет, получится линейным алгоритмом? */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> array{};
    cout << "n=";
    cin >> n;
    array.resize(n);
    int sum = 0;
    float sumn = ((1+n) / 2.0) * n;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    cout<<sum<<endl<<sumn<<endl;
    cout << "dira = " << sumn - sum;

    return 0;
}