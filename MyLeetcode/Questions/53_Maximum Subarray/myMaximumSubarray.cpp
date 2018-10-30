#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int maxacc=0, res = INT_MIN; // 注意用INT_MIN而不是初始化为零！ 
    	
    	for (auto num : nums) {
    		maxacc = max(maxacc+num, num);
    		res = max(res, maxacc);
		}
        
        return res;
    }
};

int main() {
	Solution solution;
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(a, a+9);
	
	cout << solution.maxSubArray(v) << endl;
	
	return 0;
}

// 思路：SubArray的总体和大于0的话，就认为其对后续结果是有贡献。
