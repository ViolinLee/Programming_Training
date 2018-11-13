#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int n = num.size() - 1;
		int flag = 0;
		
		for(int i = n-1; i >= 0; i--) {
			if (num[i] < num[i+1]) {
				for (int j = n; j > 0; j--) {
					if (num[j] > num[i]) {
						swap(num[i], num[j]);
						reverse(num.begin()+i+1, num.end());
						flag = 1;
	                    break;
					}
				}
				break;	
			}	
		}
		
		if (flag == 0) {
			reverse(num.begin(), num.end());
		}
	}
};

int main() {
	Solution solution;
	vector<int> num = {1,1,5};
	
	solution.nextPermutation(num);
	
	for (auto n : num) cout << n << "";
	
	return 0;
}

// 似乎做得很棒！ 
// 这里返回是void；但是后面permution会用到需要返回bool的
 
