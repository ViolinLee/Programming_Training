#include <iostream>

using namespace std;
class Solution {
public:
	void sortColors(int A[], int n) {
		// 一个是red的index，一个是blue的index，两边往中间走
		int red = 0, blue = n-1;
		
		for (int i=0; i<blue+1;) {
			if (A[i] == 0)              //使遇到的红色排在最前（最后结果） 
			    swap(A[i++], A[red++]);
			else if (A[i] == 2)         //使遇到的蓝色排在最后（最后结果） 
			    swap(A[i], A[blue--]);
			else                        //使遇到的白色排在最后一个确定红色的后一个位置 
			    i++;
		} 
	}
};

int main() {
	Solution solution;
	int A[] = {2,0,2,1,1,0};
	int n = sizeof(A)/sizeof(int);
	
	solution.sortColors(A, n);
	
	for (int i = 0; i < n; i++) 
	    cout << A[i] << "";
	    
	return 0;
}

/*
小小程序细节要注意 
1. for的条件里边没有 i++ 
2.将当前红色与最后一个确定颜色的红色的下一个位置交换后，有i++。因为交换到当前位置的颜色只可能是白色 
3.将当前蓝色与最后一个不确定颜色交换后，没有i++。因为交换到当前位置的颜色可能是红/白/蓝 
*/ 
