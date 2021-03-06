/*
两个变量的值的交换方法
*/

#include <stdio.h>

void swap1(int& a, int& b)
{
	int temp = a; // 使用局部变量 temp 完成交换，教科书做法 
	a = b;
	b = temp; 
};

void swap2(int& a, int& b)
{
	a = a + b; // 使用加减运算完成交换, 缺点是可能导致数据溢出 
	b = a - b;
	a = a - b; 
};

/*
          a     b
        1011   0110
a^=b:   1101   0110
b^=a:   1101   1011
a^=b:   0110   1011

记住结论： 
   (a^b)^a: b
   (a^b)^b: a
*/
void swap3(int& a, int& b)
{
	a ^= b; // 使用异或运算完成交换
	b ^= a;
	a ^= b;
}

int main(void)
{
	int a1 = 1, b1 = 2;
	int a2 = 3, b2 = 4;
	int a3 = 5, b3 = 6;
	int a = 2147483647, b = 1;
	
	swap1(a1, b1);  // 测试使用临时变量进行交换的版本
	swap2(a2, b2);  // 测试使用加减运算进行交换的版本
	swap3(a3, b3);  // 测试使用异或运算进行交换的版本
	
	printf("after swap...\n");
	printf("a1 = %d, b1 = %d\n", a1, b1);
	printf("a2 = %d, b2 = %d\n", a2, b2);
	printf("a3 = %d, b3 = %d\n", a3, b3);
	
	swap2(a, b);
	printf("a = %d, b = %d\n" , a, b); 
	
    return 0;
}

