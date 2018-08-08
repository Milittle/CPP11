#include"Test10.h"

void Test10::test_10_27(std::vector<int> &vecs, std::list<int> &lst)
{
	std::unique_copy(vecs.begin(), vecs.end(), std::back_inserter(lst));
}
