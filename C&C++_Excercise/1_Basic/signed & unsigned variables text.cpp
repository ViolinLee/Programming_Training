# include <stdio.h>

int main()
{
	int a = -7;
	unsigned int x = a;
	
	printf("%d\n", a);
	printf("%d\n", x);       // x = a
	
	printf("%u\n", x);       // %d、%u 会自动转换类型打印 
 
	printf("%u\n", x + 7);   // 正好溢出，值为 0 
	
	return 0;
}
