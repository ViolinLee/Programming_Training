#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;
	int &rn = a; // 申明变量 rn 为变量 a 的一个引用 
	int equal;
	
	rn = b; // 将 rn 的值复制为 b 的值。此时 rn 其实是 a 的一个别名，对 rn 赋值其实就是对 a 赋值。执行完此句，a 和 b 的值都是20 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	rn = 100; // 将 rn 赋值为100，此时 a 的值变成100 
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	// 将 a 的地址与 rn 的地址进行比较，若相等，变量 equal 的值为1，否则为0
	// 将rn声明为a的引用，不需要为rn另外开辟内存单元。rn和a 占内存中的同一个存储单元，具有同一地址 
	equal = (&a == &rn)? 1: 0; 
	
	cout << "equal = " << equal << endl;
	
	return 0;
} 
