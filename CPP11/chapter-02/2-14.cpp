#include"Test02.h"

void Test02::test_2_14()
{
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
	{
		sum += i;
	}
	// 100 0-10 sum
	std::cout << i << " " << sum << std::endl;
}