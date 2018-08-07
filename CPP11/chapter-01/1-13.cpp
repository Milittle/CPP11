#include"Test01.h"
void ex1_9()
{
	int sum = 0;
	for (int i = 50; i <= 100; i++)
	{
		sum += i;
	}
	std::cout << "sum = " << sum << std::endl;
}
void ex1_10() 
{
	for (int i = 10; i >= 0; i--) 
	{
		std::cout << "i = " << i << std::endl;
	}
}
void ex1_11() 
{
	std::cout << "please input two number:";
	int a, b;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	if (a <= b)
	{
		for (a; a <= b; a++)
		{
			std::cout << "number = " << a << std::endl;
		}
	}
	else
	{
		for (b; b <= a; b++) 
		{
			std::cout << "number = " << b << std::endl;
		}
	}
}
void Test01::test_1_13()
{
	ex1_11();
}

