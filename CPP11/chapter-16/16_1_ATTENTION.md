#����ģ�����
template<typename T>
T foo(T *p)
{
	T tmp = *p;
	return tmp;
}
#������ģ�����
template<unsigned M, unsigned N>
int compare(const char (&p)[M], const char (&p2)[N])
{
	return strcmp(p, p2);
}

��������ʹ��compare("hi", "mom")
���ʵ����һ��M����3��N����4�ĺ�������Ϊ��Ҫ���\0