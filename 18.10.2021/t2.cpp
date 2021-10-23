/*
Перевести заданное пользователем число (целое, положительное)
в заданную пользователем систему счисления (от 2  до 16). Для систем счисления
более 9 использовать буквы английского алфавита ABCDEF.
*/
#include <iostream>
#include <string>

int main()
{
    int number, n_s;
    std::cin >> number >> n_s;
    std::string result = "";
    std::string symbols[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    int str_size = 0;
    while (number > 0)
    {
        int digit = number % n_s;
        result = result + symbols[digit];
        number = number / n_s;
        str_size++;
    }
    int i = str_size - 1;
    while (i >= 0)
    {
        std::cout << result[i];
        i--;
    }
    return 0;
}