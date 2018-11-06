#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
		
		for (int i=1; i<m; i++) {     // ע�⵽��һ��/��һ���ϵĸ��Ӷ�ֻ��һ�ַ��� 
        	for (int j=1; j<n; j++) { // ����i��j����1��ʼ 
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
