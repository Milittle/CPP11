#include"Test01.h"
#include"Sales_item.h"

void Test01::test_1_23()
{
	Sales_item item;
	int cnt = 1;
	if (std::cin >> item)
	{
		Sales_item temp;
		temp = item;
		while (std::cin >> item)
		{
			if (temp.isbn() == item.isbn())
			{
				cnt++;
			}
			else
			{
				std::cout << temp.isbn() << " this book occurs " << cnt << " times " << std::endl;
				temp = item;
				cnt = 1;
			}
		}
		std::cout << temp.isbn() << " this book occurs " << cnt << std::endl;
	}
}
