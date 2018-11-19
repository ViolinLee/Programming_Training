class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[i][j] != c) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};


class Solution { //精简(如果我们发现当前某个字符和下一行对应位置的字符不相等，说明不会再有更长的共同前缀了) 
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int j = 0; j < strs[0].size(); ++j) {
            for (int i = 0; i < strs.size() - 1; ++i) {
                if (j >= strs[i].size() || j >= strs[i + 1].size() || strs[i][j] != strs[i + 1][j]) {
                    return strs[i].substr(0, j);
                }
            }
        }
        return strs[0]; //如果遍历结束前没有返回结果的话，说明第一个单词就是公共前缀，返回为结果即可。 
    }
};

// 注：substr用法 
