#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
		
		for (int i=1; i<m; i++) {     // 注意到第一行/第一列上的格子都只有一种方法 
        	for (int j=1; j<n; j++) { // 所以i和j都从1开始 
        		dp[j] += dp[j-1];
			}
		}
		
		return dp.back();
    }
};

int main() {
	Solution solution;
	cout << solution.uniquePaths(7, 3) << endl;
	
	return 0;
}
