#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop;
double duration;
#define MAXN 10  /* ����ʽ���������������ʽ����+1 */
#define MAXK 1e7 /* ���⺯������ظ����ô��� */ 
double f1 (int n, double a[], double x);
double f2 (int n, double a[], double x);

int main()
{
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ�� */
	for (i=0; i<MAXN; i++) a[i] = (double)i;
	 
	start = clock();
	for (i=0; i<MAXK; i++) /* �ظ����ú����Ի�ó�ֵ�ʱ�Ӵ���� */ 
	    f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK; /* ���㺯���������е�ʱ�� */ 
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration = %6.2e\n", duration);
	
	// ������ظ����Ż�->�������Բ��� 
	start = clock();
	for (i=0; i<MAXK; i++) 
	    f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration = %6.2e\n", duration); /* ���峤�Ȱ���С����Ϊ6λ������2λС����ʵ�ʳ��ȴ��ڸ�ʽ����λ��ʱ��ʵ��Ϊ׼ */ 
	
	return 0;
} 
 
double f1 (int n, double a[], double x) 
{
 	int i;
 	double p = a[0];
 	for (i=1; i<=n; i++) p += (a[i] * pow(x, i));
 	return p;
}
 
double f2 (int n, double a[], double x) 
{
 	int i;
 	double p = a[n];
 	for (i=n; i>n; i--) p += a[i-1] + x*p;
 	return p;
} 
