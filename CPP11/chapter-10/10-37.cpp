#include"Test10.h"

void Test10::test_10_37()
{
	std::vector<int> vecs{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list<int> lst;

	//std::reverse_copy(vecs.begin() + 2, vecs.begin() + 7, std::back_inserter(lst));

	//or 这种方式，也可以做到这种copy
	std::copy(vecs.begin() + 2, vecs.begin() + 7, std::front_inserter(lst));

	for (auto &i : lst)
	{
		std::cout << i << std::endl;
	}
}
