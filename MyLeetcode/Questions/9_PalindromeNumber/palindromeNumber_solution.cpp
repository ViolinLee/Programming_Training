#include<iostream>

using namespace std;
class Solution {
public:
	bool isPalindrome(int x) { // 时间复杂度O(1), 空间复杂度O(1) 
		if (x<0) return false;
		int d = 1; //divisor
		while (x / d >= 10) d *= 10;
		
		while (x>0) {
			int q = x / d; // quotient
			int r = x % 10; // remainder
			if (q != r) return false;
			x = x % d / 10;
			d /= 100;
		}
		return true;
	}
};

int main() {
	Solution solution;
	int a = 1221;
	cout << solution.isPalindrome(a) << endl;
	
	return 0;
}

