#include"Test03.h"

void Test03::test_3_4_1()
{
	std::string s1{ "" }, s2{ "" };
	std::cin >> s1 >> s2;

	std::cout << (s1 <= s2 ? s2 : s1) << std::endl;

}


void Test03::test_3_4_2()
{
	std::string s1{ "" }, s2{ "" };
	std::cin >> s1 >> s2;

	std::cout << (s1.size() <= s2.size() ? s2 : s1) << std::endl;
}