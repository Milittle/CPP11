#include<iostream>
#include "chapter-10/Test10.h"
#include "chapter-08/Test08.h"

int main()
{
	Test10 *test10 = new Test10;
	Test08 *test08 = new Test08;

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

	std::list<std::string> words_lst =
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

	//test10->test_10_25(words, i);
	//test10->test_10_21();
	std::string temp = "hello world";
	std::vector<int> tvec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list<int> lst;

	//test10->test_10_24(tvec, temp);
	test10->test_10_42(words_lst);

	for (auto &i : words_lst)
	{
		std::cout << i << std::endl;
	}

	delete test10;

	system("pause");
	return 0;
}