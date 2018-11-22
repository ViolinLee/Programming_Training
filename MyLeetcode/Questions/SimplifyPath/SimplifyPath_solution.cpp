#include <vector>
#include <iostream> 
#include <string.h>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back(); 
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/"; // 最后才处理'/'，先提取字符 
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};

int main() {
	Solution solution;
	string path = "/...";
	string PATH = solution.simplifyPath(path);
	
	cout << PATH;
	
	return 0;
}

// 注："/..."路径有实际意义吗？ 
