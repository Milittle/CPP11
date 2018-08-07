#include"Test01.h"
void Test01::test_1_18()
{
	int currentValue = 0, cnt = 0;
	int val;
	if (std::cin >> currentValue)
	{
		cnt++;
		val = currentValue;
		while (std::cin >> currentValue)
		{
			if (val == currentValue)
			{
				cnt++;
			}
			else
			{
				std::cout << val << " occurs " << cnt << " times " << std::endl;
				cnt = 0;
				cnt++;
				val = currentValue;
			}
		}
		std::cout << currentValue << " occurs " << cnt << " times " << std::endl;
	}
}
