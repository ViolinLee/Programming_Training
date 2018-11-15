#include <iostream> 
#include <vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int id = -1;
    	int num = gas.size();
		    	
        for(int i = 0; i < gas.size(); i++) {
        	int flag = 1;
			int gas_mount = 0; 
			
			for(int j = i; j%num <= i || (j%num > i && j <=num); j++) {
				gas_mount += gas[j%num] - cost[j%num];
				if (gas_mount < 0) {
					flag = 0;
					break;
				}
			}
			
			if (flag == 1) {
				id = i;
				break;
			}
		}
		return id;	
    }
};

int main() {
	Solution solution;
	vector<int> gas = {2,3,4};
	vector<int> cost = {3,4,3};
	
	cout << solution.canCompleteCircuit(gas, cost);
	
	return 0;
}

// 注：我这里想到的是最直接的O(n^2)解法 
