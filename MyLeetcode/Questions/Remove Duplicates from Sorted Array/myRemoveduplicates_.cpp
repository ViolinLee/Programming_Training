#include<stdio.h>
#include<iostream>

using namespace std; 

class Solution {
public:
	int removeDup(int A[], int n) {  // 函数接口中的 n 
		
		int count = 0;
		int back = -1;
		int num =n;
		
		for (int i; i < n; ) {
			if (A[i] != back) {
			    back = A[i];
			    i++;
			}
			else {
				for (int j=i; j<n-1; j++) {
					A[j] =  A[j+1];
				}
				back = A[i-1];
				n=n-1;
				count++;
			}
		}
	    
	    return num - count;
	}	
};

int main() {
	int array[]={1,1,2,3,4,4,4,5};
	Solution R;
	
	int n = R.removeDup(array, 8);
	for (int i=0;i<n;i++){
		cout << array[i];
	}
	cout << endl << n << endl; 
	
	return 0;
}
