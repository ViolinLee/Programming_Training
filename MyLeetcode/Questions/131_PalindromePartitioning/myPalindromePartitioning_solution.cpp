#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        partitionDFS(s, 0, out, res);
        return res;
    }
    void partitionDFS(string s, int start, vector<string>& out, vector<vector<string>>& res) {
    	if (start == s.size()) {
    		res.push_back(out);
    		return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (isPalindrome(s, start, i)) {
				out.push_back(s.substr(start, i - start + 1));
				partitionDFS(s, i + 1, out, res);
				out.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int start, int end) { // 判断回文字符串的"套路"要牢记 
		while (start < end) {
			if (s[start] != s[end]) return false;
			++start;
			--end;
		}
		return true;
	}
};

int main() {
	Solution solution;
	string s = "aabb";
	vector<vector<string> > res = solution.partition(s);
	for (auto r : res) {
		for (auto n : r) cout << n << " ";
		cout << endl;
	}
	
	return 0;
} 

/*
理解递归顺序：例如输入string："aabb",将输出
a a b b
a a bb
aa b b
aa bb 
*/
