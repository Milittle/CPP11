#include"Test10.h"

void Test10::test_10_6()
{
	std::vector<int> vecs;
	std::fill_n(std::back_inserter(vecs), 10, 0);

	for (auto it = vecs.cbegin(); it != vecs.cend(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}
}