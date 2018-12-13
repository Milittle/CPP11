#pragma once

#include <malloc.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include <cstring>

template<typename T>
class Test16
{
public:
	Test16() {};
	~Test16() {};

	void test_0(T a)
	{
		std::cout << a << std::endl;
	}
};

template<typename T> 
T foo(T *p)
{
	T tmp = *p;
	return tmp;
}

template<unsigned M, unsigned N>
bool compare(const char(&p1)[M], const char(&p2)[N])
{
	return strcmp(p1, p2);
}


template <typename T>
class Blob {
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T> il);

	~Blob() {}

	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }

	void push_back(T &a) { data->push_back(a); }
	void push_back(T &&a) { data->push_back(std::move(a)); }

	void pop_back();

	T& back();
	T& operator[](size_type i);

private:
	std::shared_ptr<std::vector<T>> data;

	void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>())
{
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il))
{
}

template <typename T>
void Blob<T>::pop_back()
{
	data->pop_back();
}

template <typename T>
T& Blob<T>::back()
{
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i > data->size())
		throw std::out_of_range(msg);
}

