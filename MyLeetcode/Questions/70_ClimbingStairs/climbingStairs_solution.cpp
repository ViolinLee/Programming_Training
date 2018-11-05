#include<iostream>

using namespace std;
class Solution {
public:
	int climbStairs (int n) { // ע�����еĵ���д�� 
		int prev = 0;  // prev��cur�������� 
		int cur = 1;
		for(int i=1; i<=n; ++i) { // �ӵڽ�������Ϊ1��ʼ 
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
