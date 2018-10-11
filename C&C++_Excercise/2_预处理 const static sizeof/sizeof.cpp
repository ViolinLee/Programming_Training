#include<stdio.h>
#include<string.h>
int main()
{
    char *str1 = "http://see.xidian.edu.cn/cpp/u/shipin/";
    char str2[100] = "http://see.xidian.edu.cn/cpp/u/shipin_liming/";
    char str3[] = "Hello"; // ͬ char str3[] = "Hello"; 
    char str4[] = {'H','e','l','l','o'}; 
    
    printf("strlen(str1)=%d, sizeof(str1)=%d\n", strlen(str1), sizeof(str1));
    printf("strlen(str2)=%d, sizeof(str2)=%d\n", strlen(str2), sizeof(str2));
    printf("strlen(str3)=%d, sizeof(str3)=%d\n", strlen(str3), sizeof(str3));
    printf("strlen(str4)=%d, sizeof(str4)=%d\n", strlen(str4), sizeof(str4));
    return 0;
}

