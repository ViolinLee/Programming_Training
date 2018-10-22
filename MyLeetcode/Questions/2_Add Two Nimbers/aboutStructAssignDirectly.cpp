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
        struct test t1 = {1, 2, "hello"}; // 初始化
 
        struct test t2;
        t2 = t1; // 赋值运算符
        printf("%d, %d, %s\n", t2.a, t2.b, t2.ss);
        t1.ss = "hi";
        printf("%d, %d, %s\n", t1.a, t1.b, t1.ss);
        printf("%d, %d, %s\n", t2.a, t2.b, t2.ss);
        
        cout << &t1 << endl;
        cout << &t2 << endl; // 测试结果显然居然是深拷贝！ 
        
        return 0;
}

