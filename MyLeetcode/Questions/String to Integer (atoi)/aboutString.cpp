#include<stdio.h>
#include<string>

using namespace std;

int main(){
	string s = "Hello";
	char *p = "Hi";
	char p1[] = "HI";
	char c1 = 'a';
	c1 = 1; // char���Ϳ�����������ֵ 
	int i = 0;
	i = 'A'; // int���Ϳ����ַ�����ֵ 
	
	int y = (int)s[0]; // ǿ������ת�� 
	//printf("%c", s[0]);
	//printf("%d", y);
	
	if ("a" != "b") printf("%d", 1);
}
