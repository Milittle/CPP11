#include"Test01.h"
void Test01::test_1_9()
{
	int sum = 0;
	int n = 50;
	while (n <= 100)
	{
		sum += n;
		n++;
	}
	std::cout << "sum = " << sum << std::endl;
}
