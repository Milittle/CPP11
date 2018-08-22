#include"Test11.h"


void Test11::test_11_7()
{
	std::map<std::string, std::vector<std::string>> family;
	std::string f;
	while (std::cin >> f)
	{
		std::string child;
		while (std::cin >> child)
		{
			if (child == "#")
				break;
			family[f].push_back(child);
		}
	}


	for (const auto & i : family)
	{
		std::cout << i.first << std::endl;
		for (auto it = i.second.begin(); it != i.second.end(); ++it)
		{
			std::cout << *it << "	";
		}
		std::cout << std::endl;
	}
}