#类型模板参数
template<typename T>
T foo(T *p)
{
	T tmp = *p;
	return tmp;
}
#非类型模板参数
template<unsigned M, unsigned N>
int compare(const char (&p)[M], const char (&p2)[N])
{
	return strcmp(p, p2);
}

假设我们使用compare("hi", "mom")
则会实例化一个M等于3，N等于4的函数，因为需要添加\0