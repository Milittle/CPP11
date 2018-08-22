#include"Test11.h"

char trans(char a)
{
	if (a == ',' || a == '.')
		return '\0';
	else if (a >= 'A' && a <= 'Z')
		a = a + 32;
	else
		return a;
}

void Test11::test_11_4()
{
	//使用set写排除在外的单词计数
	std::set<std::string> words{ "the", "but", "and", "or", "an", "a" };
	std::map<std::string, std::size_t> words_count;
	std::string word;
	while (std::cin >> word)
	{
		std::string temp;
		std::transform(word.begin(), word.end(), std::back_inserter(temp), ::trans);
		temp.erase(std::find(temp.begin(), temp.end(), '\0'));
		if (std::find(words.begin(), words.end(), temp) == words.end())
		{
			++words_count[temp];
		}
	}


	for (const auto & i : words_count)
	{
		std::cout << "The word: " << i.first << " Count is: " << i.second << std::endl;
	}
}