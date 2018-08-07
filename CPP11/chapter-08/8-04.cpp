#include"Test08.h"
using std::ifstream;
using std::string;
using std::vector;

void Test08::test_8_4()
{
	ifstream file("./1.txt");
	vector<string> v;
	char c[20];
	if (file) 
	{
		while (file.getline(c, 20)) 
		{
			string temp(c);
			v.push_back(temp);
		}
	}
	for (auto t : v)
	{
		std::cout << t << std::endl;
	}
}
