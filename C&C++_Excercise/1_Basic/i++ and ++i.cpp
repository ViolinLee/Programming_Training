// 看代码写输出：i++和++i的区别 
 
#include <stdio.h>

int main(void)
{
	int i = 8;
	
	printf("%d\n", ++i);   //9  9   i先自增1，再打印i的值
	printf("%d\n", --i);   //8  8
	printf("%d\n", i++);   //9  8   先打印i的值，i再自增1
	printf("%d\n", --i);   //8  9
	printf("%d\n", -i++);  //9 -8
	printf("%d\n", -i--);  //8 -9
	
	/* MY TEST BEGIN*/
	printf("%d\n", -++i);  //9 -9   -++可以通过编译 
	printf("%d\n", - --i); //9 -8   ---不能通过编译 
	/* MY TEST END*/
	
	printf("------\n");
	
	return 0;
	
}
