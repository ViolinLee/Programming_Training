#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct test
{
        int a;
        int b;
        char *ss;
};
 
int main()
{
        struct test t1 = {1, 2, "hello"}; // ��ʼ��
 
        struct test t2;
        t2 = t1; // ��ֵ�����
        printf("%d, %d, %s\n", t2.a, t2.b, t2.ss);
        t1.ss = "hi";
        printf("%d, %d, %s\n", t1.a, t1.b, t1.ss);
        printf("%d, %d, %s\n", t2.a, t2.b, t2.ss);
        
        cout << &t1 << endl;
        cout << &t2 << endl; // ���Խ����Ȼ��Ȼ������� 
        
        return 0;
}

