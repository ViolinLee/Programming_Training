#include<iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    	if (x<0) return false;
    	
		int div = 1;
		int temp = x;
		int num = 1;
		while(temp/10 > 0) { 
			temp=temp/10;
			div=div*10;   //确定整数最高位
			num+=1;       //确定整数位数
		}
		//cout << div << endl;
		//cout << temp << endl;
		//cout << num << endl;
		
	    int mid = num/2;
	    for(int i=0; i<mid; i++) {    //用while(x>0)即可 -> 两个条件同时成立 
	    	if ((x/div) == (x%10)) {
	    		x = (x % div) / 10;   //去除整数的最高位和最低位
	    		div = div/100;
			}
			else return false;
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

/*
题目要求不能通过将整数转换为字符串来做
1.如果使用字符串来做？1）转化为字符串；2）0vsn-1、1vsn-2、...
2.不使用字符串？总体思路是loop里面每次去除整数的最高位和最低位（/和%） 
*/


