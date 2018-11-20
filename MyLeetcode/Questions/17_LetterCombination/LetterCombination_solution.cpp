class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) {res.push_back(out); return;} // 基准情况 
        
        string str = dict[digits[level] - '0']; //获取这一级数字对应的字符串 
        for (int i = 0; i < str.size(); ++i) { // for里面递归 
            letterCombinationsDFS(digits, dict, level + 1, out + string(1, str[i]), res);
        }
    }
};
/*
注：看题意可马上猜出是递归类题，和Path Sum II，Subsets II，Permutations，Permutations II，Combinations，Combination Sum 和Combination Sum II 等等套路一致
1.难点：函数接口
2.for循环里面递归
3.string s(num,c) 生成一个字符串，包含num个c字符 
*/ 
