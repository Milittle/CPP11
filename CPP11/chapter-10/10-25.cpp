#include"Test10.h"


bool check_size(const std::string &a, std::size_t & sz)
{
	return a.size() > sz;
}

void Test10::test_10_25(std::vector<std::string> &words, std::vector<std::string>::size_type &sz)
{
	elimDups(words);

	std::stable_sort(words.begin(), words.end(), [](const std::string & a, const std::string &b) -> bool {return a.size() < b.size(); });

	auto wc = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, std::ref(sz)));


	auto count = wc - words.begin();

	std::cout << count << " word(s) of length " << sz << " or longer " << std::endl;

	std::for_each(words.begin(), wc, [](const std::string &a) {std::cout << a << " ";  });

	std::cout << std::endl;
}
