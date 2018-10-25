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
			// ע������debugʱ����ӵ����� if (i>0) ��ʵ�ǿ��Ա���ġ�ǰ������vectorMax()�����жϴ����vΪ��ʱ����0                            
		}
		return max(0,vectorMax(profit));
    }
};

int vectorMax(vector<int> v) {
	if (v.size() == 0) return 0;
	
	auto maxPosition = max_element(v.begin(), v.end()); // max_element ���������� ForwardIterator 
	int maxId = maxPosition - v.begin();
	
	return v[maxId];
}

int main() {
	Solution solution;
	int a[] = {7, 1, 5, 3, 6, 4};
	//int a[] = {7, 6, 4, 3, 1}; // ���Ӧ�����㣬����δ���н��� 
	vector<int> v(a, a+6);
	
	//cout << vectorMax(v); // Test function of vectorMax()
 	
	cout << solution.maxProfit(v);
	
	return 0;
}

// ������ķ������������뵽��ֱ�ӵģ�����ʱ�临�Ӷ���O(n^2) 
