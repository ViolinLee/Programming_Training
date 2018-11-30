#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	if (s.size() <= numRows) return s;
        string res;
        int numCols = s.size() / (2 * numRows - 2) * 2  + 1;
        vector<vector<char> > v(numRows, vector<char>(numCols, ' '));
		int cur = 0;
		int j = 0;
		for (int i = 0; i < numRows;) {
			if (i % (numRows-1) == 0 && i != 0) {
				for (; i > 0; i--) {
					v[i][j++] = s[cur++];
					if (cur > s.size()) break;
				}
			} else {
				v[i++][j] = s[cur++];
			}
			if (cur > s.size()) break;
		} 
		/* TEST
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
		*/
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (v[i][j] != ' ') res += v[i][j];
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


/*
思路：第一感觉是提取规律 --> 写对应坐标再找出规律
评价：比较复杂，而且细节不容易把握 
*/
