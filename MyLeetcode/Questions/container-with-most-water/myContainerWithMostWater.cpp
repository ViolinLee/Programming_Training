#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV = 0, left = 0, right = height.size() - 1;
        
		while(left < right) {
        	maxV = max(maxV, min(height[left], height[right]) * (right - left));
        	
        	if (height[left]<height[right]) left++;
        	else right--;
        	
		}
		return maxV;
    }
};

int main() {
	Solution solution;
	int s[] = {1,8,6,2,5,4,8,3,7};
	vector<int> v(begin(s), end(s)); // 灵活
	//  vector<int> v(s, s+9); // 同样合法 
	
	cout << solution.maxArea(v) << endl;
	
	// 以下两句执行结果一致-->数组变量在大多数情况下的行为类似指针；cout << s 就是打印指针的值 
	cout << s << endl;
	cout << begin(s) << endl;
	
	return 0;
}

/* 注：由于只想到O(n^2)的解法，所以直接学习solution思路，然后自己写 
solution基本思路：
    1.container 宽递减（每迭代一次宽减一），每个循环仅处理该宽下的最大面积； 
    2.桶板低的一方为宽递减的方向（假如是宽高的一方递减，下一次迭代的容积必定不大于上次的容积） 
*/ 
