#include"Test10.h"


bool IsOdd(int i) { return ((i % 2) == 1); }

void Test10::test_10_7_1()
{
	std::vector<int> vecs; std::list<int> lists; int i;
	while (std::cin >> i)
	{
		lists.push_back(i);
	}


	//����ط������Ǵ���ģ���Ϊvecs����û�д�С��
	//std::copy(lists.begin(), lists.end(), vecs.begin()); 

	//�ĳ�����������ʽ�Ϳ��Բ����ˡ���Ϊÿ��back_inserter���صĶ�����һ������λ��
	std::copy(lists.begin(), lists.end(), std::back_inserter(vecs));


	for ( auto it = vecs.crbegin(); it != vecs.crend(); ++it )
	{
		std::cout << "Value: " << *it << std::endl;
	}

}



void Test10::test_10_7_2()
{
	std::vector<int> vecs;
	//����д��Ҳ�Ǵ���ģ� ��Ϊreserve��������ҪvectorԤ������ڴ��󣬲�û��ָ��vector�Ĵ�С������ô��
	//vecs.reserve(10);
	//std::fill_n(vecs.begin(), 10, 0);

	//����д������ȷ��
	std::fill_n(std::back_inserter(vecs), 10, 0);
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}



	//������ֱ������һ��replace������replace_copy����
	std::vector<int> vecs_re_copy;
	std::replace_copy(vecs.begin(), vecs.end(), std::back_inserter(vecs_re_copy), 0, 45);


	std::cout << "------------------------------------" << std::endl;
	std::cout << "----------������ԭ��������-----------" << std::endl;

	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;
	std::cout << "----�����Ǹ��Ƶ�����һ�����������-----" << std::endl;
	for (auto it = vecs_re_copy.begin(); it != vecs_re_copy.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::replace(vecs.begin(), vecs.end(), 0, 45);

	std::cout << "------------------------------------" << std::endl;
	std::cout << "------������ԭ�������ݣ����滻�ģ�----" << std::endl;
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}

	std::replace_if(vecs.begin(), vecs.end(), IsOdd, 2);   //replace_copy_if������˵��Ҳ֪������ôʹ�ð�
	std::cout << "------------------------------------" << std::endl;
	std::cout << "------������ԭ�������ݣ����滻�ģ�----" << std::endl;
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		std::cout << "Value: " << *it << std::endl;
	}
}