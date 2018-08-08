#include"Test10.h"

bool check_size(const int &n, std::string& tar)
{
	return static_cast<unsigned>(n) > tar.size();
}

void Test10::test_10_24(std::vector<int> &vecs, std::string &target)
{
	auto wc = std::find_if(vecs.begin(), vecs.end(), std::bind(check_size, std::placeholders::_1, target));

	if (wc != vecs.end())
	{
		std::cout << *wc << std::endl;
	}
	else
	{
		std::cerr << "Nothing" << std::endl;
	}
}