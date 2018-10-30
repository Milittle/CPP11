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



//��ʹ��ָ��������õ����麯����ʱ�� �����ж�̬��
//����ʹ��virtual�ؼ��֣�ʹ�ú���ִ�ж�̬��
//�κγ����캯��֮��ķǾ�̬�������������麯��
//virtual�ؼ���ֻ�ܳ��������ڲ�����������У��������û����ⲿ�Ķ�����
//���һ�������ڻ�������virtual�ģ�����������Ҳ����ʽ�ر�����Ϊvirtual��
//isbn����������ڱ���ʱ����н����ˣ����Բ�����Quote����Bulk_Quote����õİ汾����һ�µ�
//Ҳ�Ͳ����ڶ�̬����ôһ˵
//��������Լ̳����Ի��ඨ��ĳ�Ա
//����������ĳ�Ա������һ����Ȩ���ʴӻ���̳ж����ĳ�Ա
//������ʹ�û���Ĵ���һ�����������ܷ��ʹ��г�Ա�������ܷ���˽�г�Ա
//������һ�����⣬��������Է��ʻ���ı�����Ա�������������ô��벻�ܷ����ܱ�����Ա
//��Ҳ��Ϊʲô���ǰ�price����Ϊprotected��ԭ����Ϊ��������������Ҫ��дnet_price���������

//�ܽ�һ�仰����Ҫ��virtual����������ʵ����Ա������Ϊ�ܱ�������������ö���Ϊvirtual�ĺ���ʹ�õ����Ա����ô��Ҫ����Ϊprivate
class Quote
{
public:
	explicit Quote() = default;
	explicit Quote(const std::string bookNO, double sales_price):bookNO_(bookNO), price_(sales_price){}
	virtual ~Quote() = default; //�������������ж�̬��

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
	std::size_t quantity_ = 0; //��ʾʹ�õĹ�����
	double discount_ = 0.; //��ʾ�ۿ۵�С��ֵ[0,1]
};


//������ͨ���������б���˵����Ҫ�������ࣨpublic protected private��
//��������뽫virtual��Ҫ��д�ĺ�������ʲô����
//����net_price�����ǵ����������������������������Ȼ����Ҳ���������ⶨ�壩��Ĭ�����ڲ��ᱻ�Ż�Ϊ����������
class Bulk_Quote: public Disc_Quote
{
public:

	Bulk_Quote() = default;
	Bulk_Quote(const std::string & bookNO, double price, std::size_t quantity, double discount) 
		: Disc_Quote(bookNO, price, quantity, discount){}



	virtual double net_price(std::size_t n) const override // Ĭ�Ͻ���д�ĺ�������virtual����Ȼ���Ǳ���ģ�Ϊ����ȷoverrideҲ��Ҫ����
	{
		if (n > quantity_)
			return n * (1 - discount_) * price_;
		return n * price_;
	}
};
//��������ʱ��������Ҫ����ʹ����ӿ��������࣬Ϊ�˱���ȥ�����ඨ��Ľӿ�Ҫ��
//��̬��Ա���������������ֻ��һ�ݣ����������˶���


///�ص㣺�� ��c++�������������final�Ϳ�����ֹ���౻�����൱�����������м̳в���


//ϰ��15.7
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

	//debugֻ����Լ���˽�г�Ա��ͨ��������˵���������⶯̬����
	virtual void debug(std::ostream &os) override
	{
		Quote::debug(os);
		os << "max_qty: " << max_qty_ << " discount: " << discount_ << std::endl;
	}

private:
	std::size_t max_qty_ = 10;
	double discount_ = 0.;
};