class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX; // ϸ�ڣ�����Ϊ0����� 
        
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // ������ 
        
        if (n == 1) return sign == 1 ? m : -m;
        
        while (m >= n) { //������m���ڻ���ڳ���n 
            long long t = n, p = 1;  //�������t���ڳ������������p
            while (m >= (t << 1)) { //��t������С�ڵ��ڱ�����m
                t <<= 1; //t����һ��
                p <<= 1; //p����һ��  
            }
            res += p;
            m -= t; // ��������̬�仯�������㶨 
        }
        return sign == 1 ? res : -res;
    }
};

//ԭ��ܼ򵥣�����������м���� 
