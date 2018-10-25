#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int vectorMax(vector<int> v);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit;
		for (int i=0; i<prices.size(); i++) {
        	vector<int> temp;
        	for (int j=0; j<i; j++) {
        		temp.push_back(prices[i]-prices[j]);
			}
			if (i>0) profit.push_back(vectorMax(temp)); 
			// 注意这里debug时候添加的条件 if (i>0) 其实是可以避免的。前提是在vectorMax()中先判断传入的v为空时返回0                            
		}
		return max(0,vectorMax(profit));
    }
};

int vectorMax(vector<int> v) {
	if (v.size() == 0) return 0;
	
	auto maxPosition = max_element(v.begin(), v.end()); // max_element 返回类型是 ForwardIterator 
	int maxId = maxPosition - v.begin();
	
	return v[maxId];
}

int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	//int a[] = {7, 6, 4, 3, 1}; // 结果应该是零，代表未进行交易 
	vector<int> v(a, a+6);
	
	//cout << vectorMax(v); // Test function of vectorMax()
 	
	cout << solution.maxProfit(v);
	
	return 0;
}

// 我这里的方法是最容易想到的直接的，但是时间复杂度是O(n^2) 
