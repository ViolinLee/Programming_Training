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
        if (level == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) { // for����ݹ� 
            letterCombinationsDFS(digits, dict, level + 1, out + string(1, str[i]), res);
        }
    }
};
/*
ע������������ϲ³��ǵݹ����⣬��Path Sum II��Subsets II��Permutations��Permutations II��Combinations��Combination Sum ��Combination Sum II �ȵ���·һ��
*/ 
