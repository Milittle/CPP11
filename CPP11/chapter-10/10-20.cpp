#include"Test10.h"

void Test10::test_10_20(std::vector<std::string> &words, std::vector<std::string>::size_type &sz)
{
	elimDups(words);

	auto co = std::count_if(words.begin(), words.end(), [=](const std::string &a)->bool {return a.size() > sz; });

	std::cout << "Count: "  << co << std::endl;

}
