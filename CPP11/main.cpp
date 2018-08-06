#include<iostream>
#include "chapter-10/Test10.h"

int main()
{
	Test10 *test10 = new Test10;

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

	std::size_t i = 3;

	/*test10->test_10_20(words, i);*/
	test10->test_10_21();

	delete test10;
	return 0;
}