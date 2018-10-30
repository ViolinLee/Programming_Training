#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left]; // base case: meaning there is only one element.
		int mid = left + (right - left) / 2; // calculate the middle one.
		
		// recursively call Max_Subarray_Sum to go down to base case.
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        
        // calculate the maximum subarray sum for left half part.
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        
        // calculate the maximum subarray sum for right half part.
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        
        // choose the max between res and middle range.
        return max(mmax, max(lmax, rmax));
    }
};

int main() {
	Solution solution;
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(a, a+9);
	
	cout << solution.maxSubArray(v) << endl;
	
	return 0;
}

/*
1.递归法的最内层叫做base case,可以确定具体值。 

*/ 
