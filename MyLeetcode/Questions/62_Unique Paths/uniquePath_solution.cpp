#include <iostream>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0; // 终止条件
		
		if (m ==1 && n ==1) return 1; // 收敛条件
		
		return uniquePaths(m - 1, n) + uniquePaths(m, n-1); 
    }
};

int main() {
	Solution solution;
	cout << solution.uniquePaths(7, 3) << endl;
	
	return 0;
}
