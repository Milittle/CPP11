#include"Test10.h"


bool IsOdd(int i) { return ((i % 2) == 1); }

void Test10::test_10_7_1()
{
	std::vector<int> vecs; std::list<int> lists; int i;
	while (std::cin >> i)
	{
		lists.push_back(i);
	}


	//这个地方本身是错误的，因为vecs本身没有大小。
	//std::copy(lists.begin(), lists.end(), vecs.begin()); 

	//改成下面这种形式就可以插入了。因为每次back_inserter返回的都是下一个迭代位置
	std::copy(lists.begin(), lists.end(), std::back_inserter(vecs));


	for ( auto it = vecs.crbegin(); it != vecs.crend(); ++it )
	{
		std::cout << "Value: " << *it << std::endl;
	}

}



void Test10::test_10_7_2()
{
	std::vector<int> vecs;
	//这种写法也是错误的， 因为reserve方法是向要vector预分配的内存多大，并没有指定vector的大小就是那么大
	//vecs.reserve(10);
	//std::fill_n(vecs.begin(), 10, 0);

	//这样写才是正确的
	std::fill_n(std::back_inserter(vecs), 10, 0);
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}



	//接下来直接试验一下replace方法和replace_copy方法
	std::vector<int> vecs_re_copy;
	std::replace_copy(vecs.begin(), vecs.end(), std::back_inserter(vecs_re_copy), 0, 45);


	std::cout << "------------------------------------" << std::endl;
	std::cout << "----------下面是原数组数据-----------" << std::endl;

	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;
	std::cout << "----下面是复制到另外一个数组的数据-----" << std::endl;
	for (auto it = vecs_re_copy.begin(); it != vecs_re_copy.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::replace(vecs.begin(), vecs.end(), 0, 45);

	std::cout << "------------------------------------" << std::endl;
	std::cout << "------下面是原数组数据（被替换的）----" << std::endl;
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::replace_if(vecs.begin(), vecs.end(), IsOdd, 2);   //replace_copy_if不用我说你也知道该怎么使用吧
	std::cout << "------------------------------------" << std::endl;
	std::cout << "------下面是原数组数据（被替换的）----" << std::endl;
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}
}