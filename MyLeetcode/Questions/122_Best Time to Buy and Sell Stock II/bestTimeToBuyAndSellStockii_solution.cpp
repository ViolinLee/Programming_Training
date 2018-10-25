#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sum = 0;
		for (int i=1; i<prices.size(); i++) {
			int diff = prices[i] - prices[i-1];
			if (diff > 0) sum += diff;
		}
		
		return sum;
	}
}; 

int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	 
	vector<int> v(a, a+6);
	cout << solution.maxProfit(v);
	
	return 0;
}

// 注：两两相减再求和的结果 >= 跨减求和 
