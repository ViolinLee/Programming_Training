#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
		vector<int> out;
		int n = nums.size();
		for (int len = 0; len <= n; len++) {
		    helper(nums, len, 0, out, res); 
		}
		return res;
    }
    
    void helper(vector<int> nums, int len, int level, vector<int> out, vector<vector<int> > res) {
		if (out.size() == len) {res.push_back(out); return;}
		for (int i = level; i < len; i++) {
			out.push_back(nums[i]);
			helper(nums, len, i+1, out, res);
			out.pop_back();
		}
	}
};

void print_vv(vector<vector<int> >& vv) {
	for (auto v : vv) {
		for (auto n : v) {
			cout << n << " ";
		}
		cout << endl;
	}
}

int main() {
	Solution solution;
	vector<int> input = {1, 2, 3};
	
	vector<vector<int> > res = solution.subsets(input);
	print_vv(res);
	
	return 0;
}
// 做不出来。。。 

/*
我的思路：当nums的size很大时，会有很多种长度，若逐一分类处理太麻烦，因此应该是用递归； 
那么递归思路？ --> 接口一致，for遍历各个长度，for里面调用递归。 
*/ 
