#include"Test11.h"

void Test11::test_11_8()
{
	std::string tt;
	std::vector<std::string> sset;
	while (std::cin >> tt)
	{
		if (std::find(sset.begin(), sset.end(), tt) == sset.end())
		{
			sset.push_back(tt);
		}
	}

	for (auto & i : sset)
	{
		std::cout << i << std::endl;
	}
}



void Test11::test_11_8_set()
{
	std::string tt;
	std::set<std::string> sset;
	while (std::cin >> tt)
	{
		sset.insert(tt);
	}

	for (auto & i : sset)
	{
		std::cout << i << std::endl;
	}
}