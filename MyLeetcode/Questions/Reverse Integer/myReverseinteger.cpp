#include<stdio.h>

int reverseint(int x){
	int y = x/100 * 1 + (x % 100)/10 * 10 + (x % 10) * 100;
	return y;
}

int main()
{
	int x = 120;
	printf("%d", reverseint(x));
	
	return 0;
}

/*
1.���������С����3λ���أ�
����4λʱ��int y = x/1000 * 1 + (x % 1000) * 10  + (x % 100)/10 * 100 + (x % 10) * 1000; 
*/ 
