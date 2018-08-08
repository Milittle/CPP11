#include"Test10.h"

bool isPartition(const std::string & a, std::size_t &sz)
{
	return a.size() > sz;
}

bool isSort(const std::string & a, const std::string &b)
{
	return a.size() < b.size();
}

void Test10::test_10_22(std::vector<std::string> &words, std::vector<std::string>::size_type &sz)
{
	elimDups(words);

	std::stable_sort(words.begin(), words.end(), std::bind(isSort, std::placeholders::_1, std::placeholders::_2));

	//使用绑定功能
	auto wc = std::stable_partition(words.begin(), words.end(), std::bind(isPartition, std::placeholders::_1, std::ref(sz)));


	auto count = wc - words.begin();

	std::cout << count << " word(s) of length " << sz << " or longer " << std::endl;

	std::for_each(words.begin(), wc, [](const std::string &a) {std::cout << a << " ";  });

	std::cout << std::endl;
}
