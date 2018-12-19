# 类型模板参数
template<typename T>
T foo(T *p)
{
	T tmp = *p;
	return tmp;
}
# 非类型模板参数
template<unsigned M, unsigned N>
int compare(const char (&p)[M], const char (&p2)[N])
{
	return strcmp(p, p2);
}

假设我们使用compare("hi", "mom")
则会实例化一个M等于3，N等于4的函数，因为需要添加\0

# 模板编译
普通的，我们是将函数或者类的声明放在头文件，而定义放在源文件
但是呢，在类模板和函数模板中，我们通常放在头文件一起，因为编译器也要掌握模板的定义。

# 模板是直到实例化时才生成代码的，所以好多错误很难定位
1. 编译模板本身时候出现的错误，语法错误的报错
2. 编译器遇到模板使用时候，会检查一些参数的匹配或者个数匹配
3. 模板实例化的时候，这个时候已经到了链接的时候，所以一般在程序链接的时候报错

保证传入的类型支持模板的操作是调用者的责任，而且这些类型在模板中能正常工作

# 函数模板可以推测，类模板不可以推测，所以必须指定类型



# template <typename T> void f(T&&); //绑定到非const右值
# template <typename T> void f(const T&); // 左值和const右值
