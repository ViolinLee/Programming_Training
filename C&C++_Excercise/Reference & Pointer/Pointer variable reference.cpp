#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int a = 1;
	int b = 10;
	int* p = &a; // 声明整型的指针变量 p 并初始指向 a  （这里的 int* 指 “整型指针变量”） 
	int* &pa = p; // 声明 p 的一个指针引用 pa          （这里的 int* 意味着后面的引用是 “指针的引用”） 
	              // 注： int &rn = a；指声明 rn 为整型变量 a 的一个引用，即整型引用。 
	
	(*pa)++; // 将 pa 指向的内容加 1.由于 pa 是 p 的引用，所以实际上是对 p 指向的内容加 1 
	//(*p)++;  // 和 (*pa)++; 结果一致
	//*p++;  
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "*p = " << *p << endl;
	//cout << "p = " << p << endl; 打印指针变量的值 
	
	pa = &b; // 将 pa 与 b 的地址绑定（我们前面把 pa 声明为一个指针引用） 
	(*pa)++; // *pa 即 *(&b) 即 b 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "*p = " << *p << endl;
	
	return 0;
} 
