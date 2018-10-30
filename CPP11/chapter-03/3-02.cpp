#include"Test03.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
void Test03::test_3_2_1()
{
	string s{""};
	while (std::getline(cin, s))
	{
		cout << s << endl;
	}
}

void Test03::test_3_2_2()
{
	string s{ "" };
	while (cin >> s)
	{
		cout << s << endl;
	}
}