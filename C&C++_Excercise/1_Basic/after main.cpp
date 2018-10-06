/*
atexit()函数的使用：
可以用 atexit() 函数来注册程序正常终止时要被调用的函数。并且在mian()函数结束时，调用这些函数的顺序与注册它们的顺序相反。 
*/

#include<stdlib.h>    // 使用 atexit()函数必须包含头文件 stdlib.h 
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
	printf("calling fn1()...\n");   // fn1()函数打印内容 
}

void fn2()
{
	printf("calling fn2()...\n");   // fn2()函数打印内容
}
