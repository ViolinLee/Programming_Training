#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution1 {
public:
    //
    // This solution is O(1) space dynamic programming 
    //
    // We can make sure the max profit at least be ZERO. So,
    //    1) we have two pointers (begin & end ) 
    //    2) if prices[end] - prices[begin] >  0, then move the "end" pointer to next
    //    3) if prices[end] - prices[begin] <= 0, then move the "begin" pointer to current posstion.
    //    4) tracking the max profit
    //
    // Notes:
    //    Some people think find the highest-price & lowest-price, this is wrong. 
    //    Because the highest-price must be after lowest-price
    //
    int maxProfit(vector<int> &prices) {
        
        int max=0, begin=0, end=0, delta=0;
        
        for (int i=0; i<prices.size(); i++) {
            
            end = i;
            
            delta = prices[end] - prices[begin];
            
            if (delta <= 0){ // delta <= 0意味着当前值比以前出现过的最小值还小 
                begin = i; //记录出现过的最小的值的下标 
            }
            
            if (delta > max){
                max = delta;
            }
            
        }
        
        return max;
        
    }
};

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <  2) return 0;
		int profit = 0; // 差价，也就是利润
		int cur_min = prices[0]; // 当前最小
		
		for (int i = 1; i< prices.size(); i++) {
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]); // 只要有更小的price出现，就舍弃前面数据，并将cur_min赋值为该price，即price[i]
		} 
		return profit;
	}
};


int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	//int a[] = {7, 6, 4, 3, 1}; // 结果应该是零，代表未进行交易 
	vector<int> v(a, a+6);
	cout << solution.maxProfit(v);
	
	return 0;
}

/*
注：Solution（贪心算法）明显比Solution1容易理解
问题实质就是找两两最大差值，但不等同于找最大最小值，因为大的数要在后面。
Solution中使cur_min的赋值永远落后于profit的赋值，也就保证了profit的值只根据price[i]以及i以前的cur_min获得 
*/ 
