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
宏定义展开实在预处理时期，也就是在编译之前，此时b并没有没赋值，这时地b只是一个符号。
因此第7行被展开成： a = （b+2*b+2)

修改：
#define SQR(X) ((x)*(x)) 
