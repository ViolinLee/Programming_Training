/* 
������д�����C++ ������� 

1. ���������������������־�Ϊvalue
2. mian����֮ǰ������Ϊȫ�ֱ����� main������������Ϊ�߱�����������������ͬ
3. ����printvalue��ӡ����ȫ�ֱ�����ֵ��mian�������printf��ӡ���Ǿֲ�������ֵ
4. C++����ͨ��������::ֱ�Ӳ���ȫ�ֱ�������C��֧�֣�����Ϊ.c�ļ����벻��ͨ���� 
*/ 

# include <stdio.h>

int value = 0;

void printvalue()
{
	printf("value = %d\n", value);
};

int main()
{
	int value = 0;
	
	value = 1;
	printf("value = %d\n", value);
	
	::value = 2;
	printvalue();
	
	return 0;
} 
