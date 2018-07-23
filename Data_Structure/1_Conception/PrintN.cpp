#include <stdio.h>

// 循环实现 
void PrintN(int N)
{
	int i;
	for (i=1; i<=N; i++){
		printf("%d\n", i);
	}
	return;
}

// 递归实现 
void PrintN_(int N)
{
	if (N){
		PrintN_(N - 1);
		printf("%d\n", N);
	}
	return;
}

int main()
{
	int N;
	scanf("%d", &N);
	//PrintN(N);
	PrintN_(N);
	return 0;
}
