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
#include "chapter-16/Test16.h"

int main()
{

	Blob<int> b = { 1, 2, 3, 4, 5,6 };
	std::cout << b.size() << std::endl;
	std::cout << b[5] << std::endl;
	std::cout << compare("hi", "MOM") << "\n";

	system("pause");
	return 0;
}