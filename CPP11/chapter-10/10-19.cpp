#include"Test10.h"

void Test10::test_10_19(std::vector<std::string> &words, std::vector<std::string>::size_type &sz)
{
	elimDups(words);

	std::stable_sort(words.begin(), words.end(), [](const std::string & a, const std::string &b) -> bool {return a.size() < b.size(); });

	auto wc = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a)->bool {return a.size() > sz; });


	auto count = wc - words.begin();

	std::cout << count << " word(s) of length " << sz << " or longer " << std::endl;

	std::for_each(words.begin(), wc, [](const std::string &a) {std::cout << a << " ";  });

	std::cout << std::endl;
}