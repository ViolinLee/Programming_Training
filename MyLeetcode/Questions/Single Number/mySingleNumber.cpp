#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); ++i) x ^= nums[i];
        
        return x;
    }
};

int main() {
	int s[] = {1,1,2,3,2,4,4};
	vector<int> v(s, s+10);
	Solution solution;
	
	cout << solution.singleNumber(v);
		
	return 0;
}

/*
数组的初始化不能用：int* s = {1, 2, 3, 5}。
可以使s指向数组：
int ss[] = {1, 2, 3, 4};
int* s = ss;
*/

/*
用到了异或位运算的一个"套路"：    

(a^b)^b的结果是a；
(a^a)的结果是0；
任何数(1、0)异或0的结果是任何数（任何数是int型也成立）；
任何数(1、0)异或1的结果是任何数取反； 
位运算存在"交换性"：a^b^a = a^a^b = b（即三个值进行位运算，若存在两个值相等，则结果为另一个值）。这条套路可以用来交换 a b 值。 

nums:        a     a     b     b     c     c
x:     0     a     0     b     0     c     0

nums:        a     a     b     c     b     d     d  
x:     0     a     0     b    b^c    c    c^d    c
*/
