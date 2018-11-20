#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2]; //可被初始化为任意合理值 
        int diff = abs(closest - target); // 记录差的绝对值 
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) { // 先确定一个元素
            int left = i + 1, right = nums.size() - 1; // left从i+1开始(动态)，right永远是最右下标 
            while (left < right) { // 条件 
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) { // 第一处if-比较-赋值。用处是更新diff值和closest值 
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left; // 第二处if-比较-赋值。用处是遍历 
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
diff是评价接近的指标；closest存放实现接近的结果。 
*/ 
