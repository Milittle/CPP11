#include "Test10.h"

void Test10::test_10_16(std::vector<std::string> &words, std::vector<std::string>::size_type &sz)
{
	elimDups(words);

	std::stable_sort(words.begin(), words.end(), [](const std::string & a, const std::string &b) -> bool {return a.size() < b.size(); });

	auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a)->bool {return a.size() > sz; });


	auto count = words.end() - wc;

	std::cout << count << " word(s) of length " << sz << " or longer " << std::endl;

	std::for_each(wc, words.end(), [](const std::string &a) {std::cout << a << " ";  });

	std::cout << std::endl;
}
