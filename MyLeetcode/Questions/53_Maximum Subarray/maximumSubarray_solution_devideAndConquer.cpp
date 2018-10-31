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
1.�ݹ鷨�����ڲ����base case,����ȷ������ֵ�� 
2.middle range ��mid��������ȡ���������ۼӵ����ֵ�����������κ�Ԫ�أ��Ƚϣ� 
  leftSum = max(leftSum, sum); �� maxacc = max(maxacc+num, num); ������
  ǰ���滻����Ϊ��leftSum > sum; �����滻����Ϊ��maxacc > 0 
3.�������������������˷��㴦������⣬��Ϊ�����ֲ�ͬ�Ľӿڣ�
  int maxSubArray(vector<int>& nums)
  int Max_Subarray_Sum(vector<int>& nums, int left, int right)
*/ 
