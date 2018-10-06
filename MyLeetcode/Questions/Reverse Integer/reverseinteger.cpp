#include<stdio.h>

class Solution {
public:
	int reverse (int x) {
		int r = 0;
		
		for (; x; x/= 10)
		    r = r * 10 + x % 10;
		return r;
	}
};

int main() {
	Solution a;
	int y = a.reverse(123);
	printf("%d", y);
	
	return 0;
}

/* 
利用：
1.任何长度的整数对10取模，结果为该整数个位上的数。
2. 整数除以10，得到的整数为十位、百位、千位......。
*/ 
