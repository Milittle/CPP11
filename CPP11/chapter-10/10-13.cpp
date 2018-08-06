#include"Test10.h"

bool is_more_five(const std::string & str)
{
	return str.size() >= 5;
}

void Test10::test_10_13()
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


	std::partition(words.begin(), words.end(), [](const std::string &a) {return a.size() >= 5; });

	for (auto & it : words)
	{
		std::cout << "Value: " << it.c_str() << std::endl;
	}

}