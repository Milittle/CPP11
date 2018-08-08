#pragma once
#include<vector>
#include<string>    //不包含string的话，在cout输出的时候，输出 <<符号是不能识别string，需要利用string的c_str()将string转为char才能输出
#include<list>
#include<iostream>
#include<algorithm>
#include<functional>
#include<iterator>
#include<fstream>

/**
*　其实在功能函数里面写输出语句是不太好的
*  但是是测试程序就勉强看吧
*/

class Test10
{
public:
	Test10() {};
	~Test10() {};

public:
	void elimDups(std::vector<std::string> &);
	void biggies(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_6();
	void test_10_7_1();
	void test_10_7_2();
	void test_10_9();
	void test_10_11();
	void test_10_13();
	void test_10_14();
	void test_10_15();
	void test_10_16(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_18(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_19(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_20(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_21();
	void test_10_22(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_24(std::vector<int> &, std::string &);
	void test_10_25(std::vector<std::string> &, std::vector<std::string>::size_type &);
	void test_10_27(std::vector<int> &, std::list<int> &);
	void test_10_28_back(std::vector<int> &, std::list<int> &);
	void test_10_28_front(std::vector<int> &, std::list<int> &);
	void test_10_28_insert(std::vector<int> &, std::list<int> &);
	void test_10_29();
	void test_10_30();
	void test_10_31();
	void test_10_32_1();
	void test_10_33();
	void test_10_34();
	void test_10_35();
	void test_10_36();
	void test_10_37();
	void test_10_42(std::list<std::string> &);

public:
	static void test()
	{
		std::vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int n = 3;
		auto position = std::find(a.begin(), a.end(), n);

		std::cout << "The value " << n
			<< (position != a.end() ?
				" is exist" : "the value is not exist") << std::endl;
	}
};

