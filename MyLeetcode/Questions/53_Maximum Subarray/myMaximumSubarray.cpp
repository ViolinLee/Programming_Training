#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int maxacc=0, res = INT_MIN; // ע����INT_MIN�����ǳ�ʼ��Ϊ�㣡 
    	
    	for (auto num : nums) {
    		maxacc = max(maxacc+num, num);
    		res = max(res, maxacc);
		}
        
        return res;
    }
};

int main() {
	Solution solution;
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(a, a+9);
	
	cout << solution.maxSubArray(v) << endl;
	
	return 0;
}

// ˼·��SubArray������ʹ���0�Ļ�������Ϊ��Ժ���������й��ס�
