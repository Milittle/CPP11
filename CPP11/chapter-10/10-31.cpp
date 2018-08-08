#include"Test10.h"

void Test10::test_10_31()
{
	std::istream_iterator<int> in(std::cin), eof;
	std::ostream_iterator<int> out(std::cout, " ");

	std::vector<int> vecs;

	while (in != eof)
	{
		vecs.push_back(*in++);
	}

	std::sort(vecs.begin(), vecs.end());

	std::unique_copy(vecs.begin(), vecs.end(), out);
}