#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 1, b = 2;
	int &c; // 编译错误 --> 引用类型的变量在声明的同时必须初始化 
	int &d = a;
	&d = b; // 编译错误 --> 把d作为变量b的别名 --引用只能在声明的时候被赋值，以后都不能再把该引用名作为其他变量名的别名 
	int *p;
	
	*p = 5; // 运行错误 --> 把p的内容赋为5.由于p没有被初始化，因此此时是个野指针，对野指针的内容赋值非常危险，会导致程序运行时崩溃 
	
	return 0;
}

