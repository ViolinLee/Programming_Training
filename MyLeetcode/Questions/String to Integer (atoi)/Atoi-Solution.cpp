#include<iostream>
#include<string.h> // 使用strlen()，可以对C风格的（字符串）字符数组使用 

using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        int num = 0;
        int sign = 1;
        const int n = strlen(str);
        int i = 0;
        
        while (str[i] == ' ' && i < n) i++;
        
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
    	}
    	
    	for (; i < n; i++) {
    		if (str[i] < '0' || str[i] > '9')
    		break;
    	    if (num > INT_MAX/10 || (num == INT_MAX/10 && (str[i]-'0')>INT_MAX % 10)) {
    	    	return sign==1? INT_MAX : INT_MIN;
			} 
			num = num*10 + str[i]-'0'; // 不要用 num*10 + (int)str[i]
		}
		return sign * num;
	}
};

int main() {
	Solution solution;
	int ret = solution.atoi("-123456789123");
	cout << ret;
	
	return 0;
}
