#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num = matrix.size();
        
        int left = 0, right = num-1;
		
		int res = -1;
		while(left <= right) {
			int mid = (right + left)/2;
			if (matrix[mid][0] != target) {
				if (matrix[mid][0] < target) {
					left = mid + 1;
				} 
				else right = mid - 1;
				res = right;  //  查找最后一个小于key的元素：不是 res=mid 也不是 res=left 
			}
			else {
				res = mid;
				return true;
			}	
		}
		cout << res << endl;
		
		vector<int> v = matrix[res];
		for (int i=0; i<v.size(); i++) {
			if (v[i] == target) return true;
		}
		return false;
        
    }
};

int main() {
	Solution solution;
	vector<vector<int>> vv = {{1,   3,  5,  7},
							  {10, 11, 16, 20},
							  {23, 30, 34, 50}};
	
	cout << solution.searchMatrix(vv, 30);
	
	return 0;
}

// 这一节需要总结二分搜索的套路及变种 
