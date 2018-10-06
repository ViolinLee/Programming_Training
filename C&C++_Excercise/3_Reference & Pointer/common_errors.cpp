#include <iostream>
using namespace std;

class Test
{
public:
	void f(const int& arg); 
private:
	int value;
};

void Test::f(const int& arg){
	arg = 10;  // 错误。参数arg是一个常量引用类型（因const放在引用之前），arg的值在函数体内不能被修改 
	cout << "arg = " << arg << endl;
	value = 20;
} 

int main()
{
	int a = 7; // a 被声明为整型变量 
	const int b = 10; // b被声明为整型常量
	 
	int &c = b; // 错误。上一行b被声明为整型常量，而这一行的c不是常量引用 --> const int &c = b; 
	const int &d = a; // 正确。声明d为a的常量引用 
	
	a++;
	d++;
	
	Test test;
	test.f(a);
    cout << "a = " << a << endl;
    
    return 0;
}

/* 关于引用
1.引用并非对象
2.引用必须初始化
3.引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定
4.类型要严格匹配

例外！
当存在const限定符时-->常量引用
初始化常量引用时允许用任意表达式作为初始值
——————————————————————————————————— 
总结：                                                           
对于常量类型的变量，其引用也必须是常量类型；                      23 
对于非常量类型的变量，其引用可以是非常量的，也可以是常量的；      24 
但需注意，无论什么情况，多不能使用常量引用修改其引用的变量的值。  13 
*/ 
