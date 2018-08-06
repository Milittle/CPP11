#include"Test10.h"


void Test10::test_10_14()
{
	auto f = [](int i, int j) -> int {return i + j; };
	std::cout << f(1, 2) << std::endl;
}
