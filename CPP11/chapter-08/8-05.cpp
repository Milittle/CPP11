#include"Test08.h"
using std::string;
using std::ifstream;
using std::vector;

void Test08::test_8_5()
{
	ifstream ifile("2.txt", std::ios::in);
	vector<string> v;
	char *c = new char[20];
	if (ifile.is_open()) 
	{
		while (ifile.getline(c, 20)) 
		{
			v.push_back(c);
		}
	}
	for (auto i = v.cbegin(); i != v.cend(); i++) 
	{
		std::cout << *i << std::endl;
	}
}
