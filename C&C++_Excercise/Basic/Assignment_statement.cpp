// 看代码写输出：一般赋值语句

#include <stdio.h>

int main(void)
{
	int x =3, y, z;
	
	x *= (y = z = 4); printf("x = %d\n", x);    // 先执行 z = 4，再执行 y = z 
	
	z = 2;
	x = (y = z); printf("x = %d\n", x);         // 先执行 y = z，再执行 x = y 
	x = (y == z); printf("x = %d\n", x);        // y == z 的执行结果赋值给 x。注意与上一行差别 
	x = (y & z); printf("x = %d\n", x);         // 按位与运算，y和z的值都为2，则y和z的二进制都是10 
	x = (y && z); printf("x = %d\n", x);        // 逻辑与：y 和 z的值都不为0，则y&&z结果为1 
	
	y = 4;                                      // 在此之前，x 和 z 身份一致 
	x = (y | z); printf("x = %d\n", x);        
	x = (y || z); printf("x = %d\n", x);
	
	x = (y == z)? 4: 5;                         // 三元运算符的格式：(条件表达式)? 表达式1: 表达式2  
	printf("x = %d\n", x);
	
	x = (y == z)?: (y < z)? 2: 3;
	printf("x = %d\n", x);
	
	return 0;
 } 
 
