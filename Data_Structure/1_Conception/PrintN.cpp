#include <stdio.h>

// ѭ��ʵ�� 
void PrintN(int N)
{
	int i;
	for (i=1; i<=N; i++){
		printf("%d\n", i);
	}
	return;
}

// �ݹ�ʵ�� 
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
