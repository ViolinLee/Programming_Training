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
        for (int i = 0; i < nRows; ++i) { // ���д��� 
            for (int j = i; j < s.size(); j += size) {
                res += s[j]; // ��ɫԪ�� 
                int tmp = j + size - 2 * i; //��ɫԪ�� + ���ַ�Ԫ��λ�� 
                if (i != 0 && i != nRows - 1 && tmp < s.size()) res += s[tmp]; // ��ɫԪ�� 
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
