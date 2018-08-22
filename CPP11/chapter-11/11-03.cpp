#include"Test11.h"

void Test11::test_11_3_1()
{
	//ʹ��mapд���ʼ���
	std::map<std::string, std::size_t> words_count;
	std::string word;
	while (std::cin >> word)
	{
		++words_count[word];
	}

	for (const auto & i : words_count)
	{
		std::cout << "The word: " << i.first << " Count is: " << i.second << std::endl;
	}
}

void Test11::test_11_3_2()
{
	//ʹ��setд�ų�����ĵ��ʼ���
	std::set<std::string> words{"the", "but", "and", "or", "an", "a"};
	std::map<std::string, std::size_t> words_count;
	std::string word;
	while (std::cin >> word)
	{
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (std::find(words.begin(), words.end(), word) == words.end())
		{
			++words_count[word];
		}
	}


	for (const auto & i : words_count)
	{
		std::cout << "The word: " << i.first << " Count is: " << i.second << std::endl;
	}
}