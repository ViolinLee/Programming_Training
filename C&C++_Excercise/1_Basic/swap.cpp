/*
����������ֵ�Ľ�������
*/

#include <stdio.h>

void swap1(int& a, int& b)
{
	int temp = a; // ʹ�þֲ����� temp ��ɽ������̿������� 
	a = b;
	b = temp; 
};

void swap2(int& a, int& b)
{
	a = a + b; // ʹ�üӼ�������ɽ���, ȱ���ǿ��ܵ���������� 
	b = a - b;
	a = a - b; 
};

/*
          a     b
        1011   0110
a^=b:   1101   0110
b^=a:   1101   1011
a^=b:   0110   1011

��ס���ۣ� 
   (a^b)^a: b
   (a^b)^b: a
*/
void swap3(int& a, int& b)
{
	a ^= b; // ʹ�����������ɽ���
	b ^= a;
	a ^= b;
}

int main(void)
{
	int a1 = 1, b1 = 2;
	int a2 = 3, b2 = 4;
	int a3 = 5, b3 = 6;
	int a = 2147483647, b = 1;
	
	swap1(a1, b1);  // ����ʹ����ʱ�������н����İ汾
	swap2(a2, b2);  // ����ʹ�üӼ�������н����İ汾
	swap3(a3, b3);  // ����ʹ�����������н����İ汾
	
	printf("after swap...\n");
	printf("a1 = %d, b1 = %d\n", a1, b1);
	printf("a2 = %d, b2 = %d\n", a2, b2);
	printf("a3 = %d, b3 = %d\n", a3, b3);
	
	swap2(a, b);
	printf("a = %d, b = %d\n" , a, b); 
	
    return 0;
}

