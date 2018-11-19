#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.empty()) return ""; // 若strs为空的vector，下一句直接用str[0]会出错
    	
        int min_size = strs[0].size();
        string res = "";
        
        for (auto str : strs) {
        	if (str.size() < min_size) min_size = str.size();
		}
		
		for (int i = 0; i < min_size; i++) { 
			char temp = strs[0][i];
			for ( auto str : strs) {
				if (str[i] == temp) continue;
				else return res; // 这里使用return，前面可以不需要求最小str长度，但条件要做修改(见Solution) 
			}
			res += temp;
		}
		
		return res;
    }
};

int main() {
	Solution solution;
	vector<string> s = {"dog","racecar","car"};
	
	string res = solution.longestCommonPrefix(s);
	
	cout << res << endl;
	
	return 0;
}

// 注：外层遍历元素下标、内层遍历vector元素，这和平时习惯正好相反！ 
