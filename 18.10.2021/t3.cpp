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

using namespace std;

int main()
{
	string roma = "IXCMVLD";
	string result = "";
	int number;
	cin >> number;
	while (number >= 1000)
	{
		result += roma[3];
		number = number - 1000;

	}
	while (number >= 500)
	{
		result += roma[6];
		number = number - 500;
	}
	while (number >= 100)
	{
		if(number == 400){
			result = result + roma[2] + roma[6];
			number = number - 400;
			break;
		}
		result += roma[6];
		number = number - 100;
	}
	while (number >= 10)
	{
		if(number >= 50){
			result = result + roma[5];
			number = number - 50;
		}
		if(number == 40){
			result = result + roma[1] + roma[5];
			number = number - 40;
			break;
		}
		result += roma[6];
		number = number - 10;
	}
	cout<<result;
	return 0;
}