#include<iostream>

using namespace std;
class Solution { // 使用递归，太慢可能超时 
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
		else return (climbStairs(n-1) + climbStairs(n-2));
    } 
};

int main() {
	Solution solution;
	int stairsNum = 45;
	
	cout << solution.climbStairs(stairsNum) << endl;
	return 0;
}
