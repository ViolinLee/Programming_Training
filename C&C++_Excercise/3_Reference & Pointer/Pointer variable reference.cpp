#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int a = 1;
	int b = 10;
	int* p = &a; // �������͵�ָ����� p ����ʼָ�� a  ������� int* ָ ������ָ��������� 
	int* &pa = p; // ���� p ��һ��ָ������ pa          ������� int* ��ζ�ź���������� ��ָ������á��� 
	              // ע�� int &rn = a��ָ���� rn Ϊ���ͱ��� a ��һ�����ã����������á� 
	
	(*pa)++; // �� pa ָ������ݼ� 1.���� pa �� p �����ã�����ʵ�����Ƕ� p ָ������ݼ� 1 
	//(*p)++;  // �� (*pa)++; ���һ��
	//*p++;  
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "*p = " << *p << endl;
	//cout << "p = " << p << endl; ��ӡָ�������ֵ 
	
	pa = &b; // �� pa �� b �ĵ�ַ�󶨣�����ǰ��� pa ����Ϊһ��ָ�����ã� 
	(*pa)++; // *pa �� *(&b) �� b 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "*p = " << *p << endl;
	
	return 0;
} 
