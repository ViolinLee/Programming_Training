// ������д�����һ�㸳ֵ���

#include <stdio.h>

int main(void)
{
	int x =3, y, z;
	
	x *= (y = z = 4); printf("x = %d\n", x);    // ��ִ�� z = 4����ִ�� y = z 
	
	z = 2;
	x = (y = z); printf("x = %d\n", x);         // ��ִ�� y = z����ִ�� x = y 
	x = (y == z); printf("x = %d\n", x);        // y == z ��ִ�н����ֵ�� x��ע������һ�в�� 
	x = (y & z); printf("x = %d\n", x);         // ��λ�����㣬y��z��ֵ��Ϊ2����y��z�Ķ����ƶ���10 
	x = (y && z); printf("x = %d\n", x);        // �߼��룺y �� z��ֵ����Ϊ0����y&&z���Ϊ1 
	
	y = 4;                                      // �ڴ�֮ǰ��x �� z ���һ�� 
	x = (y | z); printf("x = %d\n", x);        
	x = (y || z); printf("x = %d\n", x);
	
	x = (y == z)? 4: 5;                         // ��Ԫ������ĸ�ʽ��(�������ʽ)? ���ʽ1: ���ʽ2  
	printf("x = %d\n", x);
	
	x = (y == z)?: (y < z)? 2: 3;
	printf("x = %d\n", x);
	
	return 0;
 } 
 
