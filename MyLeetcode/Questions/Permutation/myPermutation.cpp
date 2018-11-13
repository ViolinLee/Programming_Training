#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int> > permute (vector<int> &num) {
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		
		do {
			result.push_back(num);
		} while(next_permutation(num.begin(), num.end()));
		return result;
	}
};

void print2dVector(vector<vector<int> > v) {
	for (auto vec : v) {
		for (auto num : vec) cout << num <<  ",";
		cout << endl;
	}
}

int main() {
	Solution solution;
	vector<int> num = {2, 1, 3};
	
	vector<vector<int> > res = solution.permute(num);
	
	print2dVector(res);
	
	return 0;
}
