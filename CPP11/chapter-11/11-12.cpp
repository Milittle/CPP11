#include"Test11.h"


void Test11::test_11_12()
{
	std::vector<std::pair<std::string, int>> vecs;

	std::string tmp;
	int value;
	while (std::cin >> tmp >> value)
	{
		auto v = std::make_pair(tmp, value);
		vecs.push_back(v);
	}



	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << it->first << "		" << it->second << std::endl;
	}
}