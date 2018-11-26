#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class Solution { //Grandyang
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) { // 两个for均正序，而v则倒序填充 
            for (int j = 0; j < n2; ++j) {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0'); // 相对错位的存在同一位置 
            }
        }
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        int i = n1 + n2 - 1;
        while (v[i] == 0) --i; // 首位的0需要去除!!! 不怕越界访问？
        if (i < 0) return "0";
        while (i >= 0) res.push_back(v[i--] + '0');
        return res;
    }
};

int main() {
	Solution solution;
	string str1 = "0";
	string str2 = "0";
	cout << solution.multiply(str1, str2);
	
	return 0;
}


// beat 100% 

