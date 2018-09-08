#include"Test11.h"

void Test11::test_11_9()
{

	std::vector<std::string> words = {
		"hello",
		"my",
		"name",
		"already",
		"check",
		"he",
		"she",
		"his",
		"her",
		"do"
	};

	std::map<std::string, std::list<int>> words_linelst;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			words_linelst[words.at(i)].push_back(i * 10 + j);
		}
	}
	std::cout.setf(std::ios::dec);
	for (auto i = words_linelst.begin(); i != words_linelst.end(); ++i)
	{
		std::cout << "words " << i->first << " appear in the line: ";
		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}
}
