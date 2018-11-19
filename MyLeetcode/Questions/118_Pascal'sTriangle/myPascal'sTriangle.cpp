#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> res; //二维vector中的一维vector可以是长度不一的 
    	
        for (int i = 0; i < numRows; i++) {
        	vector<int> tmp(i+1, 1);
        	
        	for(int j = 1; j < i; j++) {
        		tmp[j] = res[i-1][j-1] + res[i-1][j];
			}
        	res.push_back(tmp); // 二维vector可以用push_back添加低一维的vector 
		} 
		
		return res;
    }
};


int main() {
	Solution solution;
	int numRows = 5;
	
	vector<vector<int> > res = solution.generate(numRows);
	
	for (auto v : res) {
		for (auto n : v) {
			cout << n;
		}
		cout << endl;
	}
	
	return 0;
}

// 我的解法是在每个for loop里边先为该向量申请空间，且元素全是1。后面再对一些位置赋值；代码比答案简洁，但是相当于有两次赋值，效率不高。 
