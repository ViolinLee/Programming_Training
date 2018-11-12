#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
	void rotate(vector<vector<int>> &matrix) {
		int dim = matrix.size();
		int n = dim-1;
		int mid = n/2;
		
		for(int i=0; i<=mid; i++) {
			int temp = matrix[i][i];
			matrix[i][i] = matrix[n-i][i];
			matrix[n-i][i] = matrix[n-i][n-i];
			matrix[n-i][n-i] = matrix[i][n-i];
			matrix[i][n-i] = temp;
		}
		
	}
};

void print(vector<vector<int>> &v) {
	int n = v.size();
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << v[i][j] << "," ;
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	Solution solution;

	vector<vector<int>> vv = {{1,2,3},{4,5,6},{7,8,9}};
	print(vv);
	
	solution.rotate(vv);
	print(vv);
	
	return 0;
}

// 注：我此处使用的暴力法只用了一个for循环，只能调整对角线位置，错误 
