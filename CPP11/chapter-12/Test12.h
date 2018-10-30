#pragma once
#include<algorithm>
#include<vector>
#include<memory>
#include<initializer_list>


class Test12
{
public:
	Test12() = default;
	~Test12();
};


//使用合成拷贝构造函数和拷贝赋值运算符
//使用合成移动构造函数和移动赋值运算符
//一律使用默认的，这样在拷贝data数据的时候，就是默认的shared_ptr的引用计数
//如果引用计数为零，标准库默认实现资源的释放
class StrBlob
{
public:
	StrBlob();
	~StrBlob(){}

	typedef std::vector<std::string>::size_type size_type;
	StrBlob(std::initializer_list<std::string> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string & front();
	std::string & back();

	//overload the front and back method
	const std::string & front() const;
	const std::string & back() const;

private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(size_type i, const std::string &msg) const;
};


