#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        string res = "";
        int size = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) { // 逐行处理 
            for (int j = i; j < s.size(); j += size) {
                res += s[j]; // 黑色元素 
                int tmp = j + size - 2 * i; //红色元素 + 空字符元素位置 
                if (i != 0 && i != nRows - 1 && tmp < s.size()) res += s[tmp]; // 红色元素 
            }
        }
        return res;
    }
};

int main() {
	Solution solution;
	string s = "ABCDE";
	string res = solution.convert(s, 2);
	cout << res;
	
	return 0;
}
