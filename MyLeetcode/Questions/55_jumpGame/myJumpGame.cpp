#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int prev = 0;
        int cur = 0;
        while (cur<nums.size()-1) {
        	cur = prev + nums[prev];
        	
        	if (prev == cur) return false;
        	if (cur == nums.size() -1) return true;
        	
        	prev = cur;
		}
		
		return true;
    }
};

int main() {
	Solution solution;
	
	vector<int> v = {2,5,0,0};
	cout << solution.canJump(v);
	
	return 0;
}

// 注意：理解题目有误；maximum jump!!! 
