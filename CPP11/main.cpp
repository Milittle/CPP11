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
	int i = 10;
	char *a = "abcd";
	errorMsg(std::cout, 1, "hello", i, a);

	system("pause");
	return 0;
}