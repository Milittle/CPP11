#include"Test01.h"

void Test01::test_1_11()
{
	std::cout << "please input two number, i will show you between number1 to number2's numbers";
	int number1, number2;
	std::cout << "number1 = ";
	std::cin >> number1;
	std::cout << "number2 = ";
	std::cin >> number2;
	if (number1 > number2)
	{
		while (number2 <= number1)
		{
			std::cout << "number = " << number2 << std::endl;
			number2++;
		}
	}
	else
	{
		while (number1 <= number2)
		{
			std::cout << "number = " << number1 << std::endl;
			number1++;
		}
	}
}