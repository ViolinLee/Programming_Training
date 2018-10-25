#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int min = prices[0]; // 使用该方法min不能初始化为0！！！否则在代码中0代表开始前就购置了价值为0的股票 
		int profit = 0;
		
		for (int cur=1; cur<prices.size(); cur++) {
			if (prices[cur] > min) {
			    profit += (prices[cur] - min);
				min = prices[cur];	
			}
			else min = prices[cur];
		}
		
		return profit;
	}
}; 

int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	 
	vector<int> v(a, a+6);
	cout << solution.maxProfit(v);
	
	return 0;
}
