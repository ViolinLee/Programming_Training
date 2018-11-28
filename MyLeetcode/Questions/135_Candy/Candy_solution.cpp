class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
		vector<int> nums(n, 1);
		for (int i = 0; i < n - 1; ++i) {
			if (ratings[i + 1] > ratings[i]) nums[i + 1] = nums[i] + 1;
		} 
		
		for (int i = n - 1; i > 0; --i) {
			if (ratings[i - 1] > ratings[i]) nums[i - 1] = max(nums[i - 1], nums[i] + 1);
		}
		
		for (int num: nums) res += num;
		return res;
    }
};

/*
第一遍遍历：保证相邻两个小朋友如果右边rating高，糖果多；
第二遍遍历：保证相邻两个小朋友如果左边rating高，糖果多；
（注意二者意义接近，实现/公式不同）第一遍是比左边增1；第二遍是若已满足则不变若不满足则增1。
*/ 
