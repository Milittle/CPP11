#include"Test02.h"

void Test02::test_2_17()
{
	int i, &ri = i;
	i = 5; ri = 100;
	// 100 100
	std::cout << i << " " << ri << std::endl;
}