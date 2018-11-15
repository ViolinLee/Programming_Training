#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        
        
        return res;
    }
};

void print(vector<vector<int> > &v) {
	for (auto vec : v) {
		for (auto e : vec) {
			cout << e << " ";
		}
		cout << endl;
	}
}

int main() {
	Solution solution;
	vector<int> v = {2, 3, 6, 7};
	
	vector<vector<int> > res = solution.combinationSum(v);
	
	print_vector(res);
	
	return 0;
} 

