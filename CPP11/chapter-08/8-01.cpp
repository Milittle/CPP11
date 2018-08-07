#include"Test08.h"


using std::istream;
istream & input_stream_test(istream & input);

void Test08::test_8_1()
{
	istream & in = input_stream_test(std::cin);
	std::cout << in.rdstate() << std::endl;
}


istream & input_stream_test(istream & input){
	std::string a;
	while(input >> a){
		std::cout << a << std::endl;
	}	
	input.clear();
	return input;
}
