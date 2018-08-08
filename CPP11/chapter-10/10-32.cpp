#include"Test10.h"
#include"../chapter-01/Sales_item.h"

void Test10::test_10_32_1()
{
	std::vector<Sales_item> total;
	Sales_item trans;
	while (std::cin >> trans)
	{
		auto wc = std::find_if(total.begin(), total.end(), std::bind(compareIsbn, std::placeholders::_1, trans));
		if (wc != total.end())
		{
			*wc += trans;
		}
		else
		{
			total.push_back(trans);
		}
	}

	if (total.size() < 1)
	{
		std::cerr << "No Data!!!" << std::endl;
	}

	for (auto i : total)
	{
		std::cout << i << std::endl;
	}


}