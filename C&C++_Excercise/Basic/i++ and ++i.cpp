// ������д�����i++��++i������ 
 
#include <stdio.h>

int main(void)
{
	int i = 8;
	
	printf("%d\n", ++i);   //9  9   i������1���ٴ�ӡi��ֵ
	printf("%d\n", --i);   //8  8
	printf("%d\n", i++);   //9  8   �ȴ�ӡi��ֵ��i������1
	printf("%d\n", --i);   //8  9
	printf("%d\n", -i++);  //9 -8
	printf("%d\n", -i--);  //8 -9
	
	/* MY TEST BEGIN*/
	printf("%d\n", -++i);  //9 -9   -++����ͨ������ 
	printf("%d\n", - --i); //9 -8   ---����ͨ������ 
	/* MY TEST END*/
	
	printf("------\n");
	
	return 0;
	
}
