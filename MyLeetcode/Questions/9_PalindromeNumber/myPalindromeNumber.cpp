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
			div=div*10;   //ȷ���������λ
			num+=1;       //ȷ������λ��
		}
		//cout << div << endl;
		//cout << temp << endl;
		//cout << num << endl;
		
	    int mid = num/2;
	    for(int i=0; i<mid; i++) {    //��while(x>0)���� -> ��������ͬʱ���� 
	    	if ((x/div) == (x%10)) {
	    		x = (x % div) / 10;   //ȥ�����������λ�����λ
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
��ĿҪ����ͨ��������ת��Ϊ�ַ�������
1.���ʹ���ַ���������1��ת��Ϊ�ַ�����2��0vsn-1��1vsn-2��...
2.��ʹ���ַ���������˼·��loop����ÿ��ȥ�����������λ�����λ��/��%�� 
*/


