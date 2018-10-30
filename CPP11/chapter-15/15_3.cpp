#include"Test15.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

void Test15::test_15_3()
{
	Quote b("I123456", 10.);
	print_total(std::cout, b, 10);
}
