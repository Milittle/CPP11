#include"Test10.h"

void Test10::test_10_36()
{
	std::list<int> lst{ 0, 1, 2, 4, 0, 5, 6, 0, 8 };
	std::list<int>::reverse_iterator lc = std::find(lst.rbegin(), lst.rend(), 0);
	std::cout << *lc << std::endl;
}