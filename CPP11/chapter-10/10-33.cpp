#include"Test10.h"

void Test10::test_10_33()
{
	std::ifstream in;
	in.open("config/chapter-10/2.txt", std::ios::in);
	std::ofstream out1, out2;
	out1.open("config/chapter-10/3.txt", std::ios::out);
	out2.open("config/chapter-10/4.txt", std::ios::out);


	std::istream_iterator<int> in_iter(in), in_eof;
	std::ostream_iterator<int> out1_iter(out1, " "), out2_iter(out2, "\n");

	std::vector<int> vecs;
	while (in_iter != in_eof)
	{
		vecs.push_back(*in_iter++);
	}

	std::copy_if(vecs.begin(), vecs.end(), out1_iter, [](const int &a)->bool {return a % 2 == 1; });
	std::copy_if(vecs.begin(), vecs.end(), out2_iter, [](const int &a)->bool {return a % 2 == 0; });
}