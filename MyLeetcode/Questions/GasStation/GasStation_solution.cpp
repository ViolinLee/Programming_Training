#include <iostream> 
#include <vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};

int main() {
	Solution solution;
	vector<int> gas = {2,3,4};
	vector<int> cost = {3,4,3};
	
	cout << solution.canCompleteCircuit(gas, cost);
	
	return 0;
}

/*  注：total决定是否有解
        而题目又给出"若有解；解唯一"，因而如果total满足，且sum<0，则start就是唯一解。  
