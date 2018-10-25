#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int min = prices[0]; // ʹ�ø÷���min���ܳ�ʼ��Ϊ0�����������ڴ�����0����ʼǰ�͹����˼�ֵΪ0�Ĺ�Ʊ 
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
