#pragma once
#include<iostream>
#include<string>
#include<vector>
class Quote;
class Disc_Quote;
class Bulk_Quote;
class Over_Quote;

extern double print_total(std::ostream &os, const Quote &item, std::size_t n);

class Test15
{
public:
	Test15();
	~Test15();

	void test_15_3();
	void test_15_6();
};



//当使用指针或者引用调用虚函数的时候 将进行动态绑定
//基类使用virtual关键字，使得函数执行动态绑定
//任何除构造函数之外的非静态函数都可以是虚函数
//virtual关键字只能出现在类内部的声明语句中，而不能用户类外部的定义中
//如果一个函数在基类中是virtual的，在派生类中也是隐式地被定义为virtual的
//isbn这个函数是在编译时候进行解析了，所以不论是Quote还是Bulk_Quote类调用的版本都是一致的
//也就不存在动态绑定这么一说
//派生类可以继承来自基类定义的成员
//但是派生类的成员函数不一定有权访问从基类继承而来的成员
//和其他使用基类的代码一样，派生类能访问公有成员，而不能访问私有成员
//但是有一个例外，派生类可以访问基类的保护成员，但是其他调用代码不能访问受保护成员
//这也是为什么我们把price定义为protected的原因，因为在派生类中是需要重写net_price函数规则的

//总结一句话：需要在virtual函数里面访问的类成员，定义为受保护对象，如果不用定义为virtual的函数使用的类成员，那么需要定义为private
class Quote
{
public:
	explicit Quote() = default;
	explicit Quote(const std::string bookNO, double sales_price):bookNO_(bookNO), price_(sales_price){}
	virtual ~Quote() = default; //对析构函数进行动态绑定

	std::string isbn() const { return bookNO_; }
	virtual double net_price(std::size_t n) const { return n * price_; };

	virtual void debug(std::ostream & os)
	{
		os << "bookNO: " << bookNO_ << " price: " << price_ << std::endl;
	}

protected:
	double price_;
private:
	std::string bookNO_;
};


class Disc_Quote : public Quote
{
public:
	Disc_Quote() = default;
	Disc_Quote(const std::string &bookNO, double price, std::size_t quantity, double discount)
		:Quote(bookNO, price), quantity_(quantity), discount_(discount) {}
	virtual ~Disc_Quote() = default;

	virtual double net_price(std::size_t n) const = 0;
	virtual void debug(std::ostream &os) override
	{
		Quote::debug(os);
		os << "quantity_: " << quantity_ << " discount: " << discount_ << std::endl;
	}
protected:
	std::size_t quantity_ = 0; //表示使用的购买量
	double discount_ = 0.; //表示折扣的小数值[0,1]
};


//派生类通过类派生列表来说明需要派生的类（public protected private）
//派生类必须将virtual需要重写的函数重新什么声明
//所以net_price在我们的派生类里面进行了重新声明（当然定义也可以在类外定义）（默认类内部会被优化为内联函数）
class Bulk_Quote: public Disc_Quote
{
public:

	Bulk_Quote() = default;
	Bulk_Quote(const std::string & bookNO, double price, std::size_t quantity, double discount) 
		: Disc_Quote(bookNO, price, quantity, discount){}



	virtual double net_price(std::size_t n) const override // 默认将复写的函数叫上virtual，虽然不是必须的，为了明确override也需要加上
	{
		if (n > quantity_)
			return n * (1 - discount_) * price_;
		return n * price_;
	}
};
//在设计类的时候，我们需要保持使用类接口来操作类，为了避免去打破类定义的接口要求
//静态成员在类的声明周期内只有一份，不管派生了多少


///重点：※ 在c++中类名后面加上final就可以阻止该类被其他类当作基类来进行继承操作


//习题15.7
class Over_Quote : public Quote
{
public:
	Over_Quote() = default;
	Over_Quote(const std::string & bookNO, double price, std::size_t max_qty, double discount):
		Quote(bookNO, price), max_qty_(max_qty), discount_(discount){}

	virtual double net_price(std::size_t n) const override
	{
		if (n > max_qty_)
			return n * price_;
		return n * (1 - discount_) * price_;
	}

	//debug只输出自己的私有成员：通过作用域说明符来避免动态调用
	virtual void debug(std::ostream &os) override
	{
		Quote::debug(os);
		os << "max_qty: " << max_qty_ << " discount: " << discount_ << std::endl;
	}

private:
	std::size_t max_qty_ = 10;
	double discount_ = 0.;
};