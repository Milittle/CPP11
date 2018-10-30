#include<iostream>
#include<cctype>
#include<functional>
#include<memory>
#include<string>

#include "chapter-02/Test02.h"
#include "chapter-03/Test03.h"
#include "chapter-10/Test10.h"
#include "chapter-08/Test08.h"
#include "chapter-11/Test11.h"
#include "chapter-12/Test12.h"
#include "chapter-13/Test13.h"
#include "chapter-15/Test15.h"

int main()
{
	Test15 tt;
	tt.test_15_6();
	int i = 1;

	std::cout << (i >> 1) << std::endl;

	std::cout << __FILE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << __LINE__ << std::endl;

	system("pause");
	return 0;
}