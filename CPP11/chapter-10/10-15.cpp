#include"Test10.h"


void Test10::test_10_15()
{
	int i = 5;

	auto f = [i](int g)->int {return g + i; };


	std::cout << f(6) << std::endl;
}
