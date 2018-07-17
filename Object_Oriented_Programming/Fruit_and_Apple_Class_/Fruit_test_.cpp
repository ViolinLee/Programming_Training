// 为上周题目中的 Fruit和Apple 添加 构造函数与 析构函数， 
// 并在构造函数与析构函数中打印控制台信息，观察构造和析枸调用过程。
// 然后为Apple类重载 ::operator new 和 ::operator delete，在控制台打印信息，并观察调用结果。

#include <iostream>
#include "Fruit_.h"

using namespace std;

int main(){
	cout << "******************** Test 1 ********************" << endl;
	Apple* a = new Apple;     
	delete a;    // 这种情况，父类的析构函数不加virtual，也不会造成 memory leak 
	Apple* A = new Apple[2];
	delete[] A;  // 此处应该用array delete，否则造成内存泄露 
	
	cout << endl;
	cout << "******************** Test 2 ********************" << endl;
	Fruit* f = new Apple;
	delete f;    // 如果父类的析构函数不加virtual，则只调用父类的析构函数而不调用子类的析构函数，造成内存泄露
	Fruit* F = new Apple[2];  
	delete[] F;  // 程序中断？？？ 在VC上不会！！！ 
	
	return 0;
}


// 注意到控制台的打印信息：
// 用new创建对象时，先调用operator new创建空间，再调用构造函数； 
// 用delete删除对象时，先调用析构函数，再调用operator delete释放内存。


// 内部隐性调用关系：
// new -> (operator new -> malloc) + 构造函数      
// delete -> 析构函数 + (operator delete -> free)

  
// operator new，内部调用malloc分配内存；
// operator delete，内部调用free释放内存。 

