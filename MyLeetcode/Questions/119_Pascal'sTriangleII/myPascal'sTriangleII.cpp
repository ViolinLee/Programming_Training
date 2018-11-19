#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res;
    	if (rowIndex < 0) return res;
		 
        res.assign(rowIndex + 1, 1); // 如果不是要判断rowIndex < 0的情况，直接 vector<int> res(rowIndex + 1, 1)即可 
        for (int i = 1; i <= rowIndex; i++) {
        	for (int j = i-1; j > 0; j--) { // 因为递归时会用到下标j-1，因此只能用减递归 
        		res[j] = res[j-1] + res[j];
			}
		}
		return res;
    }
};

int main() {
	Solution solution;
	int numRows = 3;
	
	vector<int> res = solution.getRow(numRows);
	
	for (auto n : res) cout << n;

	return 0;
}
