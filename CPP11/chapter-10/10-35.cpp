#include"Test10.h"

void Test10::test_10_35()
{
	std::vector<int> vecs{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::reverse(vecs.begin(), vecs.end());
	for (auto rit = vecs.begin(); rit != vecs.end(); ++rit)
	{
		std::cout << *rit << std::endl;
	}
}
