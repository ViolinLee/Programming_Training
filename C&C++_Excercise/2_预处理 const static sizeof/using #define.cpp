#include<stdio.h>
#define SQR(x) (x*x)

int main()
{
	int a, b = 3;
	a = SQR(b+2);
	printf("a = %d\n", a);
	return 0;
}

/*
�궨��չ��ʵ��Ԥ����ʱ�ڣ�Ҳ�����ڱ���֮ǰ����ʱb��û��û��ֵ����ʱ��bֻ��һ�����š�
��˵�7�б�չ���ɣ� a = ��b+2*b+2)

�޸ģ�
#define SQR(X) ((x)*(x)) 
