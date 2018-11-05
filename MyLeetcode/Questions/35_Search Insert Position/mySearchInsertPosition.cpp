#include<iostream> 
#include<vector>
#include<string.h>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		for (int i=0; i<nums.size(); i++) {
			if (target <= nums[i]) return i;
		}
		if (target > nums[0]) return nums.size();
		else return 0;
    }
};

int main() {
	Solution solution;
	
	int N[] = {1, 3, 5, 6};
	vector<int> nums(N, N+4);
	int target = 0;
	
	cout << solution.searchInsert(nums, target);
	
	return 0;
}


// 考察的是二分搜索法，而不是上面这种 
