#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class Solution { //根据Grandyang思路改成正序版本 
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2, carry = 0;
        
        if (k < 1) return 0;
        
        vector<int> v(k, 0); // 注意长度为n1和n2的数相乘，乘出来长度最多n1+n2 
        
        for(int i = 0; i < n1; i++) {
        	for(int j = 0; j < n2; j++) {
        		v[i+j+1] += (num1[i] - '0') * (num2[j] - '0'); // 正序版本 
			}
		}
		
		for(int i = k-1; i >= 0; i--) {
			v[i] += carry;
			carry = v[i] / 10;
			v[i] = v[i] % 10;
		}
		
		int cur = 0;
		while(cur < k && v[cur] == 0) ++cur;
		if (cur > k-1) return "0";
		while(cur < k) res.push_back(v[cur++] + '0');
		
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
