#include <iostream>	
#include <string>
#include <sstream>
using namespace std;

// type_traits类型定义 
template<typename T>
struct type_traits{ typedef typename T::type_traits valueType; };

// meter类型声明 
struct meter
{
	typedef meter type_traits;
private:
	string m_str;
public:
	static int m_conv;
	meter(string str):m_str(str){}
	meter(double val, int con=1)
	{
		stringstream sstring;
		sstring << val*con;
		sstring >> m_str;
		m_str = m_str + "m";
	}
	meter(const meter& met){ m_str = met.m_str; }
	meter& operator=(const meter& met)
	{
		this->m_str = met.m_str;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const meter& str)
	{
		os << str.getSting();
		return os;
	}
	string getSting() const { return m_str; }
};

// kilometer类型声明 
struct kilometer
{
	typedef meter type_traits;
public:
	static int m_conv;
};

// second类型声明 
struct second
{
	typedef second type_traits;
private:
	string m_str;
public:
	static int m_conv;
	second(string str):m_str(str){}
	second(double val, int con=1)
	{
		stringstream sstring;
		sstring << val*con;
		sstring >> m_str;
		m_str = m_str + "s";
	}
	second(second& met)
	{
		m_str = met.m_str;
	}
	friend ostream& operator<<(ostream& os, const second& str)
	{
		os << str.getSting();
		return os;
	}
	string getSting() const { return m_str; }
};

// minute类型声明 
struct minute
{
	typedef second type_traits;
public:
	static int m_conv;
};

// Measurement类型声明 
template<typename I>
struct Measurement
{
private:
	double value;
public:
	Measurement(double val):value(val){}
	typename type_traits<I>::valueType description()
	{
		typedef typename type_traits<I>::valueType valType;
		int iconv = I::m_conv;
		valType typeVal(value, iconv);
		return typeVal;
	}
};

// Measurement模板特化
// 代表所有其他单位的泛化版本 
template<>
struct Measurement<double>
{
private:
	double value;
public:
	Measurement(double val):value(val){}
	string description()
	{
		stringstream sstring;
		string str;
		sstring << value;
		sstring >> str;
		return str;
	}
};

int meter::m_conv = 1;
int kilometer::m_conv = 1000;
int second::m_conv = 1;
int minute::m_conv = 60;

// 测试函数： 
int main(void)
{
	Measurement<meter> m1 = 20;
	Measurement<kilometer> m2 = 11.2;
	meter me =  m1.description();   
	Measurement<second> m3 = 20;
	Measurement<minute> m4 = 10;
	Measurement<double> m5 = 10;
	
	cout << me << endl;
	cout << m2.description() << endl;
	cout << m3.description() << endl;
	cout << m4.description() << endl;
	cout << m5.description() << endl;
	
	return 0;
}
