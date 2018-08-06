#include"Test10.h"

void Test10::test_10_21()
{
	int i = 10;
	int j = 10;

	//引用捕获可以直接修改
	auto f = [&]() -> bool {return --i; };

	//值捕获方式必须通过mutable来指定修改已经捕获的值
	auto ff = [=]() mutable->bool {return --j; };


	bool sign;
	while(sign = f())
	{
		std::cout << sign << " ";
	}
	std::cout << std::endl;
	std::cout << "The last sign is: " << sign << std::endl;
	
	//看看i是不是发生的改变
	std::cout << "the value (i) become: " << i << std::endl;

	while (sign = ff())
	{
		std::cout << sign << " ";
	}
	std::cout << std::endl;
	std::cout << "The last sign is: " << sign << std::endl;


	//看到j并没有发生任何的改变
	std::cout << "the value (j) become: " << j << std::endl;


	//以上示例展示了（=）值捕获和（&）引用捕获的区别

	//还有需要说的
	/*
	* lambda表达式有7种捕获方式
	* 1. 显示空捕获[]
	* 2. 显示值捕获[n] n是一个值传递的捕获列表（局部对象）
	* 3. 显示引用捕获[&n] 是一个引用捕获的捕获列表（也是局部对象，但是说明，在调用lambda函数对象的时候，局部引用对象必须存在）
	* 4. 隐含值捕获[=] 在函数体内可以使用任意局部对象
	* 5. 隐含引用捕获[&] 在函数体内可以使用任意局部对象（在调用lambda函数对象的时候，局部引用对象必须存在）
	* 6. 隐含和显示捕获共存[&, 值捕获] 前面有了隐式引用捕获，那么后面必须值捕获
	* 7. 隐含和显示捕获共存[=, 引用捕获] 前面有了隐式值捕获，那么后面必须引用捕获
	*/


	///最最后，需要注意的是， lambda可以直接使用static对象，可以直接使用作用域中的全局对象，但是函数局部对象必须捕获使用
	///综上所述，那么，lambda尽量少用引用捕获，因为你不知道局部对象在什么时候会被销毁，很危险。
	///还有就是在lambda生成的时候就已经确定了值捕获的值，也就是已经存在在lambda对象里面了。所以后续调用的时候只不过是使用一下而已
}
