#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/* 由于限定了O(n)的时间，所以一般的排序方法都不能用*/

// NOT constant space(没有使用排序，但非常数空间，)
class Solution_bad {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> s;
        for (int num : nums) {
            if (num <= 0) continue;
            s.insert(num);
            mx = max(mx, num); // 使用hashset，找出max value？会不会set更好，set是有序插入元素 
        }
        for (int i = 1; i <= mx; ++i) {
            if (!s.count(i)) return i;
        }
        return mx + 1;
    }
};

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) { //覆盖正确位置但不一定有序!!! 
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] -1] != nums[i]) { //nums[i] <= n可以避免nums[nums[i] - 1]越界 
				swap(nums[i], nums[nums[i] - 1]); // 太巧妙了... 
			}
		}
		
		for (auto n : nums) cout << n << " "; // test the "for-while" result
		
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
}; 

int main() {
	Solution solution;
	vector<int> test = {7, 5, 2, 1, 3}; // 经过覆盖正确位置变成 1 2 3 7 5 
	cout << endl << solution.firstMissingPositive(test);
	
	return 0;
}



/*
关键在while循环
如果 nums[i] > n 则直接跳过？ 
*/
