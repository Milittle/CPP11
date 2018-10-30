#pragma once
#include<vector>
class Test13
{
public:
	Test13();
	~Test13();
};


class SIX_C_TEST
{
public:
	explicit SIX_C_TEST() = default;
	~SIX_C_TEST() = default;

	explicit SIX_C_TEST(std::string str) :str_(str) {}

	SIX_C_TEST(SIX_C_TEST const &) = delete;
	SIX_C_TEST & operator = (SIX_C_TEST const &) = delete;

	explicit SIX_C_TEST(SIX_C_TEST &&) = delete;
	SIX_C_TEST & operator = (SIX_C_TEST &&) = delete;

private:
	std::vector<int> data_;
public:
	std::string str_;
};

