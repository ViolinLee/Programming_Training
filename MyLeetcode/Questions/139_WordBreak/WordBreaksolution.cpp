class Solution { // brute force string分段，去worddict中找。而不是从worddict取word去string找...... 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // 实现常数时间查找 
		vector<int> memo(s.size(), -1); // memo[i]定义为范围为[0, i)的子字符串是否可以拆分
		return check(s, wordSet, 0, memo); 
    }
    bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
    	if (start >= s.size()) return true;
    	if (memo[start] != -1) return memo[start];
    	for (int i = start + 1; i <= s.size(); ++i) {
    		if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) { // 虽然理解，但贼抽象。。。 
    			return memo[start] = 1;
			}
		}
	}
	return memo[start] = 0;
};


class Solution { // dp解法（理解状态转移是关键，也是难点） 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
