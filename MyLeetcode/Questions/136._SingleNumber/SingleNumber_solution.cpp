/*
本来是一道非常简单的题，但由于限制时间复杂度O(n)，空间复杂度O(1)，
使得不能用排序方法，也不能使用map数据结构。
解决方法——抓住"every element appears twice except for one",可以使用bit operation：
把数组所有数异或，每对相同数字得0，则最后剩下的数字就是那个只有1次的数字。 
*/ 

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int res = 0; // 0异或任何数结果是原数 
		for (auto num : nums) res ^= num;
		return res;
	}
};
