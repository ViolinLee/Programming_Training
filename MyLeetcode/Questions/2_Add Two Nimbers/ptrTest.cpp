/*
char *cp = "abcdefg"; // char *cp; cp = &"abcdefg";
int *p = 2; // int *p; *p = 2; 
int *p1; int *p2; *p1 = 2; *p2 = 3; p1 = p2; // 改变p1所指向的地址（常见） 
int *p1; int *p2 = &p1;
int *p1 = 2; int *p2 = p1; // ? int *p1 = 2; 是错误的
int *p1; *p1 = 2; //是错误的。第一句指针定义时没有初始化指向了随机地址；
int a = 3; int* p1 = 3; int* p2 = p1;
*/

#include<iostream>
#include<string.h>

using namespace std;
int main() {
	/* 
	int *p1; 
	*p1 = 2; // 编译通过，运行宕机；VS2008则提示：The variable 'p' is being used without being initialized. 
	cout << 1;  
	*/
	
	/*
	int a = 2;
	int* p = &a;
	*p = 3;
	cout << a << endl;
	
	char* s = "hello!";
	cout << &s << endl;
	cout << strlen(s) <<endl; 
	s = "hi"; //编译和运行均通过；（猜测：编译器自动释放字符串"hello"，然后再开辟给"hi"） 注：这里不能使用 *s 来改变数组 
	//s[2] = 'c'; // 编译通过，但是运行错。（字符串常量不能修改） 
	cout << s << endl;
	cout << &s << endl; //所以地址没有改变 
	cout << strlen(s) <<endl;
	*/
	int a = 3; 
	int* p1 = &a; 
	int* p2 = p1; //pass，等同于：int* p2; p2 = p1; 指针初始化（或者p=这种格式）时，右边的值必须是地址；而指针的值就是地址。 
	cout << *p2;
	 
	return 0;
}
