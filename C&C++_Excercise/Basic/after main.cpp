/*
atexit()������ʹ�ã�
������ atexit() ������ע�����������ֹʱҪ�����õĺ�����������mian()��������ʱ��������Щ������˳����ע�����ǵ�˳���෴�� 
*/

#include<stdlib.h>    // ʹ�� atexit()�����������ͷ�ļ� stdlib.h 
#include<stdio.h>

void fn1(void);
void fn2(void);

int main(void)
{
	atexit(fn1);
	atexit(fn2);
	printf("mian exit...\n");
	return 0;
} 

void fn1()
{
	printf("calling fn1()...\n");   // fn1()������ӡ���� 
}

void fn2()
{
	printf("calling fn2()...\n");   // fn2()������ӡ����
}
