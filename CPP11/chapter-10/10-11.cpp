#include"Test10.h"

bool isOrder(const std::string & a, const std::string & b)
{
	return a.size() < b.size();
}

void Test10::test_10_11()
{
	std::vector<std::string> words =
	{
		"the",
		"quick",
		"red",
		"fox",
		"jump",
		"over",
		"the",
		"slow",
		"red",
		"turtle"
	};



	elimDups(words);

	std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {return a.size() < b.size(); });


	for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it)
	{
		//怎么auto不能自动识别string了
		std::cout << it->c_str() << std::endl;
	}
}