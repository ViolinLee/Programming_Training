class Solution1 { // 贪婪算法 
public:
	bool canJump(vector<int>& A) {
		nums = A.size();
		
		int reach = 1; // 最右能跳到哪里
		for (int i = 0; i < reach && reach < nums; ++i)
		    reach = max(reach, i + 1 + A[i]); // 记录在A[i]处能达到的最大层 
		return reach >= nums; // 注：reach从1开始; i从0开始 
	}
}; 


class Solution2 { // 动态规划 
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1; //状态转移方程（注：Hidden Information隐藏信息f(0)=0; i>0） 
            if (dp[i] < 0) return false;
        }
        return dp.back() >= 0;
    }
};
/*
1. f(i)中的i>0;因为必须是至少跳跃一次后，讨论剩余步数才有意义 
2.当前位置的剩余步数dp[i],和上一个位置的剩余步数dp[i-1]以及上一位置能跳的最远距离A[i]有关。
这两个值的较大值，决定了上一位置所能达到的最远距离。这个距离减去1，就得到到达当前位置的剩余步数。
当到达某一位置的剩余步数小于零时，证明不能到达这一位置，以及以后的所有位置。 
*/ 


