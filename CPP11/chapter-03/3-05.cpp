#include"Test03.h"

void Test03::test_3_5_1()
{
	std::string s{ "" };
	std::string sum_s{ "" };
	while (std::cin >> s)
	{
		sum_s += s;
	}

	std::cout << sum_s << std::endl;
}

void Test03::test_3_5_2()
{
	std::string s{ "" };
	std::string sum_s{ "" };
	while (std::cin >> s)
	{
		sum_s += s + " ";
	}

	std::cout << sum_s << std::endl;
}