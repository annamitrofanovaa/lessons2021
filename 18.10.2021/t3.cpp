/*
Перевести заданное целое число (<4000) в систему римского счета.
	Система римских цифр использует особые знаки для десятичных разрядов I=1, X=10, C=100, M=1000
и их половин V=5, L=50, D=500.
	Натуральные числа записываются при помощи повторения этих цифр. При этом, если большая цифра
стоит перед меньшей, то они складываются, если же меньшая перед большей, то меньшая вычитается
из большей. Последнее правило применяется во избежание четырехкратного повторения одной и той же цифры.
	 Например, XL=50-10=40 вместо XXXX.
Максимально возможное число, записанное по правилам в римской системе счисления 3999.
*/
#include <iostream>
#include <string>

int main()
{
	std::string roma = "IXCMVLD";
	std::string result = "";
	int number;
	std::cin >> number;

	while (number >= 1000)
	{
		result += roma[3];
		number -= 1000;
	}

	if (number >= 900)
	{
		result += roma[2];
		result += roma[3];
		number -= 900;
	}
	if (number >= 500)
	{
		result += roma[6];
		number -= 500;
	}
	while (number >= 100)
	{
		if (number == 400)
		{
			result = result + roma[2] + roma[6];
			number -= 400;
			break;
		}
		result += roma[2];
		number -= 100;
	}

	if (number >= 90)
	{
		result += roma[1];
		result += roma[2];
		number -= 90;
	}
	while (number >= 10)
	{
		if (number >= 50)
		{
			result = result + roma[5];
			number -= 50;
		}
		if (number == 40)
		{
			result = result + roma[1] + roma[5];
			number -= 40;
			break;
		}
		if (number < 10)
			break;

		result += roma[1];
		number -= 10;
	}
	if (number == 9)
	{
		result += roma[0];
		result += roma[1];
		number -= 9;
	}
	while (number > 0)
	{
		if (number >= 5)
		{
			result = result + roma[4];
			number -= 5;
		}
		if (number == 4)
		{
			result += roma[0];
			result += roma[4];
			number -= 4;
		}
		if (number == 0)
			break;
		result += roma[0];
		number -= 1;
	}
	std::cout << result;
	return 0;
}