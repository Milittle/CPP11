#include"Test10.h"

void Test10::test_10_28_back(std::vector<int> &vecs, std::list<int> &lst)
{
	std::copy(vecs.begin(), vecs.end(), std::back_inserter(lst));
}

void Test10::test_10_28_front(std::vector<int> &vecs, std::list<int> &lst)
{
	std::copy(vecs.begin(), vecs.end(), std::front_inserter(lst));
}

void Test10::test_10_28_insert(std::vector<int> &vecs, std::list<int> &lst)
{
	std::copy(vecs.begin(), vecs.end(), std::inserter(lst, lst.begin()));
}