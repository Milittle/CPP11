#include"Test10.h"

void Test10::test_10_29()
{
	std::ifstream in("config/chapter-10/1.txt", std::ios::in);

	std::istream_iterator<std::string> in_iter(in), eof;
	std::vector<std::string> vecs;
	while (in_iter != eof)
	{
		vecs.push_back(*in_iter++);
	}

	for (auto it : vecs)
	{
		std::cout << it << std::endl;
	}
}