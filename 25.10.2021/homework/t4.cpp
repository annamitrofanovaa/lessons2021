/*Составьте программу, читающую целое положительное число,
не превышающее миллиард, и выводящее это же число на естественном языке.
*/
#include <iostream>
#include <clocale>

int get_power(int n)
{
    int res = 1;
    for (int i = 0; i < n; ++i)
    {
        res *= 10;
    }
    return res;
}

int get_digit(int num, int k)
{
    return (num % get_power(k)) / get_power(k - 1);
}

void p_endnum(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "миллионов ";
        break;
    case 1:
        std::cout << "тысяч ";
        break;
    case 3:
        std::cout << "миллион ";
        break;
    case 4:
        std::cout << "тысяча ";
        break;
    case 6:
        std::cout << "миллиона ";
        break;
    case 7:
        std::cout << "тысячи ";
        break;
    }
}

void p_h100(int n)
{
    switch (n)
    {
    case 1:
        std::cout << "сто ";
        break;
    case 2:
        std::cout << "двести ";
        break;
    case 3:
        std::cout << "триста ";
        break;
    case 4:
        std::cout << "четыреста ";
        break;
    case 5:
        std::cout << "пятьсот ";
        break;
    case 6:
        std::cout << "шестьсот ";
        break;
    case 7:
        std::cout << "семьсот ";
        break;
    case 8:
        std::cout << "восемьсот ";
        break;
    case 9:
        std::cout << "девятьсот ";
        break;
    }
}

void p_des10(int n)
{
    switch (n)
    {
    case 2:
        std::cout << "двадцать ";
        break;
    case 3:
        std::cout << "тридцать ";
        break;
    case 4:
        std::cout << "сорок ";
        break;
    case 5:
        std::cout << "пятьдесят ";
        break;
    case 6:
        std::cout << "шестьдесят ";
        break;
    case 7:
        std::cout << "семьдесят ";
        break;
    case 8:
        std::cout << "восемьдесят ";
        break;
    case 9:
        std::cout << "девяносто ";
        break;
    }
}

void p_ten(int n)
{
    switch (n)
    {
    case 0:
        std::cout << "десять";
        break;
    case 1:
        std::cout << "одиннадцать ";
        break;
    case 2:
        std::cout << "двенадцать ";
        break;
    case 3:
        std::cout << "тринадцать ";
        break;
    case 4:
        std::cout << "четырнадцать ";
        break;
    case 5:
        std::cout << "пятнадцать ";
        break;
    case 6:
        std::cout << "шестнадцать ";
        break;
    case 7:
        std::cout << "семнадцать ";
        break;
    case 8:
        std::cout << "восемнадцать ";
        break;
    case 9:
        std::cout << "девятнадцать ";
        break;
    }
}

void prt_rus_dig(int n)
{
    switch (n)
    {
    case 1:
        std::cout << "один ";
        break;
    case 2:
        std::cout << "два ";
        break;
    case 3:
        std::cout << "три ";
        break;
    case 4:
        std::cout << "четыре ";
        break;
    case 5:
        std::cout << "пять ";
        break;
    case 6:
        std::cout << "шесть ";
        break;
    case 7:
        std::cout << "семь ";
        break;
    case 8:
        std::cout << "восемь ";
        break;
    case 9:
        std::cout << "девять ";
        break;
    case 11:
        std::cout << "одна ";
        break;
    case 12:
        std::cout << "две ";
        break;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    do
    {
        std::cout << "input number:" << std::endl;
        std::cin >> n;
    } while (n < 1 || n > 1000000000);

    if (n == 1000000000)
    {
        std::cout << "один миллиард" << std::endl;
        return 0;
    }
    int number[3][3];
    for (int i = 0; i < 9; ++i)
    {
        number[i / 3][i % 3] = get_digit(n, 9 - i);
    }
    for (int i = 0; i < 9; ++i)
    {
        std::cout << number[i / 3][i % 3] << " ";
    }
    for (int i = 0; i < 3; ++i)
    {
        p_h100(number[i][0]);
        if (number[i][1] == 1)
        {
            p_ten(number[i][2]);
        }
        else
        {
            p_des10(number[i][1]);
            if (i == 1 && number[i][2] < 3)
            {
                prt_rus_dig(number[i][2] + 10);
            }
            else
            {
                prt_rus_dig(number[i][2]);
            }
        }
        if (number[i][0] + number[i][1] + number[i][2] != 0)
        {

            if (number[i][1] == 1 || number[i][2] > 4 || number[i][2] == 0)
            {
                p_endnum(i);
            }
            else if (number[i][2] == 1)
            {
                p_endnum(i + 3);
            }
            else
            {
                p_endnum(i + 6);
            }
        }
    }
}
