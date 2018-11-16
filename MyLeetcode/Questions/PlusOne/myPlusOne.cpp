#include<iostream>
#include<vector>

using namespace std;
class Solution1 { // 我的这种解法不管任何情况都需要遍历完整个向量，不够高效 
public:
	vector<int> plusOne(vector<int>& num) {
		vector<int> res(num.size());
		int carry = 0;
		int n = num.size() - 1;
		
		for (int i = n; i >=0; i--) {
			int sum;
			if (i == n) {
				sum = num[i] + 1;
			} else {
				sum = num[i] + carry;
			}
			carry = sum > 9 ? 1 : 0; // carry = sum / 10; 
			res[i] = sum % 10;
		}
		
		if (carry == 1) res.insert(res.begin(), 1);
		
		return res;
	}
}; 

class Solution { 
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int carry = 1, n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (carry == 0) return digits; // 上一加操作没有进位则直接返回 
            int sum = digits[i] + carry; // 把一开始加上的"1"视为进位！ 
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
	Solution solution;
	vector<int> v = {7, 9, 9};
	
	vector<int> res = solution.plusOne(v);
	
	for (auto n : res) cout << n;
	
	return 0;
}

//结果正确，但不够简洁 
