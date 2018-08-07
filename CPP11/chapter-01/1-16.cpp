#include"Test01.h"

void Test01::test_1_16()
{
	int n;
	int sum = 0;
	while (std::cin >> n)
	{
		sum += n;
	}
	std::cout << "sum = " << sum << std::endl;
}
