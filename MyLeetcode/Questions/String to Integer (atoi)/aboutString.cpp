#include<stdio.h>
#include<string>

using namespace std;

int main(){
	string s = "Hello";
	char *p = "Hi";
	char p1[] = "HI";
	char c1 = 'a';
	c1 = 1; // char类型可用整数来赋值 
	int i = 0;
	i = 'A'; // int类型可用字符来赋值 
	
	int y = (int)s[0]; // 强制类型转换 
	//printf("%c", s[0]);
	//printf("%d", y);
	
	if ("a" != "b") printf("%d", 1);
}
