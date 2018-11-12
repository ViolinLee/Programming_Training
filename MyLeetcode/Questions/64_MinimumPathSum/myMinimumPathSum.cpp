#include<iostream> 
#include<vector>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();

        int res = minPath(grid, m-1, n-1);
        
        return res;
    }
    int minPath(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) return grid[0][0]; // 基条件的确定？看能不能以此推出下一个条件 
        if (i < 0 || j < 0) return INT_MAX; // 偷懒巧妙处理 

        return min(minPath(grid, i-1, j), minPath(grid, i, j-1)) + grid[i][j];
	}
};

int main() {
	Solution solution;
	vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1}};
	
	cout << solution.minPathSum(grid);
	
	return 0;
}

/*
思路：递归 
minPath[i][j] = min(minPath[i-1][j], minPath[i][j-1]) + grid[i][j];
注意：我这种解法可能超时；增加一个缓存的步骤，可以避免这个缺陷 
*/ 

