/*
�з��ű������޷��ű�����ֵ��ת�� 
*/ 

# include <stdio.h>

char getChar(int x, int y)
{
	char c;
	unsigned int a = x;              // �Ѳ��� x ��ֵת��Ϊ�޷������� 
	
	(a + y > 10)? (c = 1): (c = 2);  // ���ʽ�д����з������ͺ��޷�������ʱ���з��������Զ�ת�����޷������� 
	return c;
} 

int main(void)
{
	char c1 = getChar(7, 4);          
	char c2 = getChar(7, 3);
	char c3 = getChar(7, -7);        // -7ת��Ϊ�޷�������,�� 7 ������������ֵΪ 0  
	char c4 = getChar(7, -8);        // -8ת��Ϊ�޷�������,�� 7 ��Ӳ� 1 �����ֵΪ 4294967295 ��4���ֽڣ���ͬ���������ܲ�ͬ�� 
	
	printf("c1 = %d\n", c1);
	printf("c2 = %d\n", c2);
	printf("c2 = %d\n", c3);
	printf("c2 = %d\n", c4);
	
	return 0;
}

