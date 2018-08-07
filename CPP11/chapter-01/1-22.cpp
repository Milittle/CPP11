#include"Test01.h"
#include"Sales_item.h"

void Test01::test_1_22()
{
	Sales_item item[5];
	Sales_item sum;
	for (int i = 0; i < 5; i++) 
	{
		std::cin >> item[i];
	}
	sum = item[0];
	for (int j = 1; j < 5; j++) 
	{
		sum += item[j];
	}
	std::cout << sum << std::endl;
}
