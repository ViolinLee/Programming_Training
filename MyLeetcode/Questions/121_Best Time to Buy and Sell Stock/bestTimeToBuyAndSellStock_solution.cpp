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
            
            if (delta <= 0){ // delta <= 0��ζ�ŵ�ǰֵ����ǰ���ֹ�����Сֵ��С 
                begin = i; //��¼���ֹ�����С��ֵ���±� 
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
		int profit = 0; // ��ۣ�Ҳ��������
		int cur_min = prices[0]; // ��ǰ��С
		
		for (int i = 1; i< prices.size(); i++) {
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]); // ֻҪ�и�С��price���֣�������ǰ�����ݣ�����cur_min��ֵΪ��price����price[i]
		} 
		return profit;
	}
};


int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	//int a[] = {7, 6, 4, 3, 1}; // ���Ӧ�����㣬����δ���н��� 
	vector<int> v(a, a+6);
	cout << solution.maxProfit(v);
	
	return 0;
}

/*
ע��Solution��̰���㷨�����Ա�Solution1�������
����ʵ�ʾ�������������ֵ��������ͬ���������Сֵ����Ϊ�����Ҫ�ں��档
Solution��ʹcur_min�ĸ�ֵ��Զ�����profit�ĸ�ֵ��Ҳ�ͱ�֤��profit��ֵֻ����price[i]�Լ�i��ǰ��cur_min��� 
*/ 
