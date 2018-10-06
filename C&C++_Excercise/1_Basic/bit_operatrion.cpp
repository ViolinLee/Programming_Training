#include<stdio.h>

int func(int x)
{
    int countx = 0;    
     while (x)
     {
      countx ++;
      x = x & (x - 1); // What about && ?
     }
     return countx;
}

int main()
{
    int x = 9999;
    printf("%d",func(x));
    
    return 0;
}
