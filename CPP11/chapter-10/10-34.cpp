#include"Test10.h"

void Test10::test_10_34()
{
	std::vector<int> vecs{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto rit = vecs.crbegin(); rit != vecs.crend(); ++rit)
	{
		std::cout << *rit << std::endl;
	}
}