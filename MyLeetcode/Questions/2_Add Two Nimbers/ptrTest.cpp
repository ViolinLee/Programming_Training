/*
char *cp = "abcdefg"; // char *cp; cp = &"abcdefg";
int *p = 2; // int *p; *p = 2; 
int *p1; int *p2; *p1 = 2; *p2 = 3; p1 = p2; // �ı�p1��ָ��ĵ�ַ�������� 
int *p1; int *p2 = &p1;
int *p1 = 2; int *p2 = p1; // ? int *p1 = 2; �Ǵ����
int *p1; *p1 = 2; //�Ǵ���ġ���һ��ָ�붨��ʱû�г�ʼ��ָ���������ַ��
int a = 3; int* p1 = 3; int* p2 = p1;
*/

#include<iostream>
#include<string.h>

using namespace std;
int main() {
	/* 
	int *p1; 
	*p1 = 2; // ����ͨ��������崻���VS2008����ʾ��The variable 'p' is being used without being initialized. 
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
	s = "hi"; //��������о�ͨ�������²⣺�������Զ��ͷ��ַ���"hello"��Ȼ���ٿ��ٸ�"hi"�� ע�����ﲻ��ʹ�� *s ���ı����� 
	//s[2] = 'c'; // ����ͨ�����������д����ַ������������޸ģ� 
	cout << s << endl;
	cout << &s << endl; //���Ե�ַû�иı� 
	cout << strlen(s) <<endl;
	*/
	int a = 3; 
	int* p1 = &a; 
	int* p2 = p1; //pass����ͬ�ڣ�int* p2; p2 = p1; ָ���ʼ��������p=���ָ�ʽ��ʱ���ұߵ�ֵ�����ǵ�ַ����ָ���ֵ���ǵ�ַ�� 
	cout << *p2;
	 
	return 0;
}
