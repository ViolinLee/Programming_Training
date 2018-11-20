#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2]; //�ɱ���ʼ��Ϊ�������ֵ 
        int diff = abs(closest - target); // ��¼��ľ���ֵ 
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) { // ��ȷ��һ��Ԫ��
            int left = i + 1, right = nums.size() - 1; // left��i+1��ʼ(��̬)��right��Զ�������±� 
            while (left < right) { // ���� 
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) { // ��һ��if-�Ƚ�-��ֵ���ô��Ǹ���diffֵ��closestֵ 
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left; // �ڶ���if-�Ƚ�-��ֵ���ô��Ǳ��� 
                else --right;
            }
        }
        return closest;
    }
};

int main() {
	Solution solution;
	vector<int> numbers = {-1, 2, 1, -4};
	int target = 1;
	
	int res = solution.threeSumClosest(numbers, target);
	cout << res;
	
	return 0;
} 

/*
diff�����۽ӽ���ָ�ꣻclosest���ʵ�ֽӽ��Ľ���� 
*/ 
