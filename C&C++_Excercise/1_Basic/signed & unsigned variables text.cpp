# include <stdio.h>

int main()
{
	int a = -7;
	unsigned int x = a;
	
	printf("%d\n", a);
	printf("%d\n", x);       // x = a
	
	printf("%u\n", x);       // %d��%u ���Զ�ת�����ʹ�ӡ 
 
	printf("%u\n", x + 7);   // ���������ֵΪ 0 
	
	return 0;
}
