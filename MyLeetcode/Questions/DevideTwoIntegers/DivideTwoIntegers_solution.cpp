class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX; // 细节：除数为0；溢出 
        
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // 技巧性 
        
        if (n == 1) return sign == 1 ? m : -m;
        
        while (m >= n) { //被除数m大于或等于除数n 
            long long t = n, p = 1;  //定义变量t等于除数；定义计数p
            while (m >= (t << 1)) { //当t的两倍小于等于被除数m
                t <<= 1; //t扩大一倍
                p <<= 1; //p扩大一倍  
            }
            res += p;
            m -= t; // 被除数动态变化；除数恒定 
        }
        return sign == 1 ? res : -res;
    }
};

//原理很简单，复杂在许多中间变量 
