#include<iostream>
#include<string.h>
using namespace std;

void swap(char* &x, char* &y) // 利用 “传指针引用”实现字符串交换；若改为 swap(char* x, char* y)则不能实现目的 
{
	char *temp;
	temp=x;
	x=y;
	y=temp;
}

int main()
{
	char *ap = "hello";
	char *bp = "how are you?";
	
	cout << "ap:" << ap << endl;
	cout << "bp:" << bp << endl;
	
	swap(ap, bp);
	
	cout << "swap ap,bp" << endl;
	cout << "ap:" << ap << endl;
	cout << "bp:" << bp << endl;
	
	return 0;
}

// 由于sawp函数是指针引用类型，因此传入函数的就是实参，而不是形参
// 如果不用(指针)引用，那么(指针)交换只能再swap函数种有效，因为在函数体中，函数栈会分配两个临时的指针变量分别指向两个指针参数，对实际的ap和bp没影响 



/*
1.值传递
  find (int x) {}
  find(z) 
2.地址传递 --> 引用传递
  find(int &x) {}
  find(z)
3.const引用传递 
  find(const int &x){}
  find(z)
*/ 
