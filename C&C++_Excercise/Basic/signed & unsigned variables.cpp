/*
有符号变量和无符号变量的值的转换 
*/ 

# include <stdio.h>

char getChar(int x, int y)
{
	char c;
	unsigned int a = x;              // 把参数 x 的值转换为无符号整型 
	
	(a + y > 10)? (c = 1): (c = 2);  // 表达式中存在有符号类型和无符号类型时，有符号类型自动转换成无符号类型 
	return c;
} 

int main(void)
{
	char c1 = getChar(7, 4);          
	char c2 = getChar(7, 3);
	char c3 = getChar(7, -7);        // -7转换为无符号整型,与 7 相加正好溢出，值为 0  
	char c4 = getChar(7, -8);        // -8转换为无符号整型,与 7 相加差 1 溢出，值为 4294967295 （4个字节；不同编译器可能不同） 
	
	printf("c1 = %d\n", c1);
	printf("c2 = %d\n", c2);
	printf("c2 = %d\n", c3);
	printf("c2 = %d\n", c4);
	
	return 0;
}

