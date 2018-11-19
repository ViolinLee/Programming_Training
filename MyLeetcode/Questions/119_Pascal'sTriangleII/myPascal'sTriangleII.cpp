#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res;
    	if (rowIndex < 0) return res;
		 
        res.assign(rowIndex + 1, 1); // �������Ҫ�ж�rowIndex < 0�������ֱ�� vector<int> res(rowIndex + 1, 1)���� 
        for (int i = 1; i <= rowIndex; i++) {
        	for (int j = i-1; j > 0; j--) { // ��Ϊ�ݹ�ʱ���õ��±�j-1�����ֻ���ü��ݹ� 
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
