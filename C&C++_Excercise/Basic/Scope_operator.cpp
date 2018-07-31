/* 
看代码写输出：C++ 域操作符 

1. 程序中有两个变量，名字均为value
2. mian函数之前声明的为全局变量； main函数内声明的为具备变量；二者作用域不同
3. 函数printvalue打印的是全局变量的值，mian函数里的printf打印的是局部变量的值
4. C++可以通过操作符::直接操作全局变量，而C不支持（命名为.c文件编译不能通过） 
*/ 

# include <stdio.h>

int value = 0;

void printvalue()
{
	printf("value = %d\n", value);
};

int main()
{
	int value = 0;
	
	value = 1;
	printf("value = %d\n", value);
	
	::value = 2;
	printvalue();
	
	return 0;
} 
