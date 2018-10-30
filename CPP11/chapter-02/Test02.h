#pragma once
#include<iostream>
#include<string>
class Test02
{
public:
	static Test02 & getInstance(){
		Test02 test02;
		return test02;
	}
	Test02();
	~Test02();
public:
	void test_2_3();
	void test_2_8();
	void test_2_13();
	void test_2_14();
	void test_2_17();
};

