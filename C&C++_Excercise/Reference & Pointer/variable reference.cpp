#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;
	int &rn = a; // �������� rn Ϊ���� a ��һ������ 
	int equal;
	
	rn = b; // �� rn ��ֵ����Ϊ b ��ֵ����ʱ rn ��ʵ�� a ��һ���������� rn ��ֵ��ʵ���Ƕ� a ��ֵ��ִ����˾䣬a �� b ��ֵ����20 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	rn = 100; // �� rn ��ֵΪ100����ʱ a ��ֵ���100 
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	// �� a �ĵ�ַ�� rn �ĵ�ַ���бȽϣ�����ȣ����� equal ��ֵΪ1������Ϊ0
	// ��rn����Ϊa�����ã�����ҪΪrn���⿪���ڴ浥Ԫ��rn��a ռ�ڴ��е�ͬһ���洢��Ԫ������ͬһ��ַ 
	equal = (&a == &rn)? 1: 0; 
	
	cout << "equal = " << equal << endl;
	
	return 0;
} 
