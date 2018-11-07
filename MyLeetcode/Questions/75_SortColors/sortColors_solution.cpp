#include <iostream>

using namespace std;
class Solution {
public:
	void sortColors(int A[], int n) {
		// һ����red��index��һ����blue��index���������м���
		int red = 0, blue = n-1;
		
		for (int i=0; i<blue+1;) {
			if (A[i] == 0)              //ʹ�����ĺ�ɫ������ǰ��������� 
			    swap(A[i++], A[red++]);
			else if (A[i] == 2)         //ʹ��������ɫ�������������� 
			    swap(A[i], A[blue--]);
			else                        //ʹ�����İ�ɫ�������һ��ȷ����ɫ�ĺ�һ��λ�� 
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
СС����ϸ��Ҫע�� 
1. for���������û�� i++ 
2.����ǰ��ɫ�����һ��ȷ����ɫ�ĺ�ɫ����һ��λ�ý�������i++����Ϊ��������ǰλ�õ���ɫֻ�����ǰ�ɫ 
3.����ǰ��ɫ�����һ����ȷ����ɫ������û��i++����Ϊ��������ǰλ�õ���ɫ�����Ǻ�/��/�� 
*/ 
