#include<iostream>
#include<string.h>
using namespace std;

void swap(char* &x, char* &y) // ���� ����ָ�����á�ʵ���ַ�������������Ϊ swap(char* x, char* y)����ʵ��Ŀ�� 
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

// ����sawp������ָ���������ͣ���˴��뺯���ľ���ʵ�Σ��������β�
// �������(ָ��)���ã���ô(ָ��)����ֻ����swap��������Ч����Ϊ�ں������У�����ջ�����������ʱ��ָ������ֱ�ָ������ָ���������ʵ�ʵ�ap��bpûӰ�� 



/*
1.ֵ����
  find (int x) {}
  find(z) 
2.��ַ���� --> ���ô���
  find(int &x) {}
  find(z)
3.const���ô��� 
  find(const int &x){}
  find(z)
*/ 
