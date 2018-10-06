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
1)第4行首先定义了名为DEBUG的预处理器常量；
2)该程序从终端每次读(getchar)一个字符，若字符为 q 或者 Q，程序退出，否则打印收到的字符。
3)执行结果：
input:   A
output:  i = 1, we got:A
input:   a
output:  i = 2, we got:a
input:   q
output:  we got:q, about to exit.

Note:以上输出含有"we got"字符串的，均为#ifdef与#endif之间的打印消息 
4)如果注释第4行，即 DEBUG 没有被定义，那么#ifdef与#endif之间的打印消息将不会被输出。 
*/
