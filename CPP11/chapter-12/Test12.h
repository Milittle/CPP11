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


//ʹ�úϳɿ������캯���Ϳ�����ֵ�����
//ʹ�úϳ��ƶ����캯�����ƶ���ֵ�����
//һ��ʹ��Ĭ�ϵģ������ڿ���data���ݵ�ʱ�򣬾���Ĭ�ϵ�shared_ptr�����ü���
//������ü���Ϊ�㣬��׼��Ĭ��ʵ����Դ���ͷ�
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


