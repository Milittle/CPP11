#include"Test10.h"

void Test10::test_10_9()
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


	for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it)
	{
		//怎么auto不能自动识别string了
		std::cout << it->c_str() << std::endl;
	}
}