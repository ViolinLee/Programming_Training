#include<iostream>

using namespace std;
int main() {
	int *max_left = new int[3](); // max_left的所有元素被初始化为0；注意int[3]()中的括号！！！ 
	cout << max_left[0] << endl << max_left[1] << endl;
	
	int a[3];
	cout << a[0] << endl << a[1] << endl << a[2]; // 不确定值 
	
	return 0;
} 
