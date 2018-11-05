#include<iostream>

using namespace std;
class Solution {
public:
	int climbStairs (int n) { // 注意数列的迭代写法 
		int prev = 0;  // prev和cur两个变量 
		int cur = 1;
		for(int i=1; i<=n; ++i) { // 从第阶梯数量为1开始 
			int tmp = cur;
			cur += prev;
			prev = tmp;
		} 
		return cur;
	}
};

int main() {
	Solution solution;
	int stairsNum = 45;
	
	cout << solution.climbStairs(stairsNum) << endl;
	return 0;
}
