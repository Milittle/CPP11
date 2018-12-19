#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <filesystem>
#include <cstring>
#include <type_traits>
#include <typeinfo>

template <typename T, unsigned M>
constexpr int get_size(const T(&a)[M])
{
	return M;
}

template <typename T, unsigned M>
const T* begin1(const T (&a)[M])
{
	return &a[0];
}

template <typename T, unsigned M>
const T* end1(const T (&a)[M])
{
	printf("%d\n", M);
	return &(a[M - 1]) + 1;
}

template <unsigned M>
void print(const char(&p)[M])
{
	std::cout << p << std::endl;
}

template <typename Iterator, typename value_type>
Iterator find1(Iterator begin, Iterator end, const value_type &value)
{	for (auto it = begin; it != end; ++it)
	{
		if (*it == value)
			return it;
	}
	return end;
}

template <typename T>
int compare(const T &a, const T &b)
{
	return a < b ? -1 : a == b ? 0 : 1;
}

template <>
int compare(const char * const &a, const char * const &b)
{
	return strcmp(a, b);
}


// func pointer
int(*p_compare) (const int &a, const int &b) = compare;

// func param pointer
int func(int(*pp)(const int &a, const int &b), const int &aa, const int &bb)
{
	return pp(aa, bb);
}

int compare_1(const int &a, const int &b)
{
	return a < b ? -1 : a == b ? 0 : 1;
}

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


//List
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType>&);

	~List();

	void insert(ListItem<elemType> *ptr, elemType value);
private:
	ListItem<elemType> *first, *end;
};

template <typename It>
auto fcn(It beg, It end) ->decltype(*beg)
{
	return *beg;
}

template <typename It>
auto fcn_remove_ref(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type
{
	return *beg;
}



// write a overload tempalte 
// can debug print any type defined the << operator
template <typename T> std::string debug_rep(const T &a)
{
	std::ostringstream os;
	os << a;
	return os.str();
}

//此情况不适合char*的情况，因为char*有了一个<<运算符指向了以\0为结束符的打印函数
//在char*的情况下，只能输出第一个字符。
template <typename T> std::string debug_rep(T *a)
{
	std::ostringstream os;

	//can fit the const char* and char* type
	/*if (typeid(std::remove_reference<decltype(a)>::type) == typeid(const char*) || 
		typeid(std::remove_reference<decltype(a)>::type) == typeid(char*))
	{
		os << a;
		return os.str();
	}*/

	if (a)
		os << debug_rep(*a);
	else
		os << "NUll pointer";
	return os.str();
}

//spc template for const char *
template <>
std::string debug_rep(const char * a)
{
	std::ostringstream os;
	os << a;
	return os.str();
}

//spc template for char *
template <>
std::string debug_rep(char * a)
{
	std::ostringstream os;
	os << a;
	return os.str();
}

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... args)
{
	return print11(os, debug_rep(args)...);
}

template <typename T>
std::ostream &print11(std::ostream &os, const T &t)
{
	return os << t << std::endl;
}

template <typename T, typename... Args>
std::ostream &print11(std::ostream &os, const T &t, const Args&... args)
{
	os << t << " ";
	return print11(os, args...);
}
