#include <vector>
#include <iostream>

using namespace std;


class Solution {
public: 
    int maxSubArray(vector<int>& nums) {
        // Solution: Divide and Conquer. O(nlogn)
        if(nums.empty()) return 0;
        
        return Max_Subarray_Sum(nums, 0, nums.size()-1);
    }
    
    int Max_Subarray_Sum(vector<int>& nums, int left, int right) {
        if(left == right)    // base case: meaning there is only one element.
            return nums[left];
        
        int middle = (left + right) / 2;    // calculate the middle one.
        
        // recursively call Max_Subarray_Sum to go down to base case.
        int left_mss = Max_Subarray_Sum(nums, left, middle);    
        int right_mss = Max_Subarray_Sum(nums, middle+1, right);
        
        // set up leftSum, rightSum and sum.
        int leftSum = INT_MIN;
        int rightSum = INT_MIN;
        int sum = 0;
        
        // calculate the maximum subarray sum for right half part.
        for(int i=middle+1; i<= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        
        sum = 0;    // reset the sum to 0.
        
        // calculate the maximum subarray sum for left half part.
        for(int i=middle; i>= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        // choose the max between left and right from down level.
        int res = max(left_mss, right_mss);
        
        // choose the max between res and middle range.
        return max(res, leftSum + rightSum);   
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
2.middle range 从mid向左右求取子列连续累加的最大值，不能跳过任何元素！比较： 
  leftSum = max(leftSum, sum); 和 maxacc = max(maxacc+num, num); 的区别：
  前者替换条件为：leftSum > sum; 后者替换条件为：maxacc > 0 
3.定义了两个函数，除了方便处理分类外，还为了两种不同的接口：
  int maxSubArray(vector<int>& nums)
  int Max_Subarray_Sum(vector<int>& nums, int left, int right)
*/ 
