class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || (s.size()) > 1 && s[0] == '0') return 0;
		vector<int> dp(s.size() + 1, 0); // dp长度？ 
		dp[0] = 1; //dp第一项为1；
		for (int i = 1; i < dp.size(); ++i) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1]; // 相当于dp[i] += dp[i-1] 
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) { //dp[i] += dp[i-2]  
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
    }
};
/* 
递推公式 dp[i] = dp[i-1] + dp[i-2]
事实上，dp[0]没有意义，只是为了公式合理；
因为size==1，和size==2的情况是确定的，但在size==3开始才能实际使用公式，为了size==2也能应用公式，所以引入了dp[0] = 1 
0  1 （若s.empty返回0） 
1  1
2  2
3  3 (s[3])
*/ 
