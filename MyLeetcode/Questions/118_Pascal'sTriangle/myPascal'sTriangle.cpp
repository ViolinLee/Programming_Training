#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> res; //��άvector�е�һάvector�����ǳ��Ȳ�һ�� 
    	
        for (int i = 0; i < numRows; i++) {
        	vector<int> tmp(i+1, 1);
        	
        	for(int j = 1; j < i; j++) {
        		tmp[j] = res[i-1][j-1] + res[i-1][j];
			}
        	res.push_back(tmp); // ��άvector������push_back��ӵ�һά��vector 
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

// �ҵĽⷨ����ÿ��for loop�����Ϊ����������ռ䣬��Ԫ��ȫ��1�������ٶ�һЩλ�ø�ֵ������ȴ𰸼�࣬�����൱�������θ�ֵ��Ч�ʲ��ߡ� 
