#include<iostream>

using namespace std;
int main() {
	int *max_left = new int[3](); // max_left������Ԫ�ر���ʼ��Ϊ0��ע��int[3]()�е����ţ����� 
	cout << max_left[0] << endl << max_left[1] << endl;
	
	int a[3];
	cout << a[0] << endl << a[1] << endl << a[2]; // ��ȷ��ֵ 
	
	return 0;
} 
