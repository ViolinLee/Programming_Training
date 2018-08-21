#include<stdio.h>
#include<stdlib.h>

#define DEBUG

int main()
{
	int i = 0;
	char c;
	
	while(1){
		i++;
		c = getchar();
		if (c != '\n'){
			getchar();
		}
		if (c == 'q' || c == 'Q'){
#ifdef DEBUG
                printf("we got:%c, about to exit.\n", c);
#endif
                break; 
		} else{
			    printf("i = %d", i);
#ifdef DEBUG
                printf(", we got:%c", c);
#endif
                printf("\n");
		}
	}
	
	return 0;
}

/* 
1)��4�����ȶ�������ΪDEBUG��Ԥ������������
2)�ó�����ն�ÿ�ζ�(getchar)һ���ַ������ַ�Ϊ q ���� Q�������˳��������ӡ�յ����ַ���
3)ִ�н����
input:   A
output:  i = 1, we got:A
input:   a
output:  i = 2, we got:a
input:   q
output:  we got:q, about to exit.

Note:�����������"we got"�ַ����ģ���Ϊ#ifdef��#endif֮��Ĵ�ӡ��Ϣ 
4)���ע�͵�4�У��� DEBUG û�б����壬��ô#ifdef��#endif֮��Ĵ�ӡ��Ϣ�����ᱻ����� 
*/
