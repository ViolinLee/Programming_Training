#include <iostream>
#include <math.h>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        
        while(left <= right) {
        	int mid = (left + right) / 2;
        	if (pow(mid, 2) == x) return mid;
        	if (pow(mid, 2) > x) right = mid -1;
			else left = mid + 1; 
		}
		return right;
    }
};

int main() {
	Solution solution;
	int x = 9;
	int res = solution.mySqrt(x);
	
	cout << res;
	
	return 0;
}

/*
通过OJ，并且beats 97.58%......
用了<math.h>的pow函数！
*/ 
