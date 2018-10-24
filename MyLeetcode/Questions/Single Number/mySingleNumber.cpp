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
����ĳ�ʼ�������ã�int* s = {1, 2, 3, 5}��
����ʹsָ�����飺
int ss[] = {1, 2, 3, 4};
int* s = ss;
*/

/*
�õ������λ�����һ��"��·"��    

(a^b)^b�Ľ����a��
(a^a)�Ľ����0��
�κ���(1��0)���0�Ľ�����κ������κ�����int��Ҳ��������
�κ���(1��0)���1�Ľ�����κ���ȡ���� 
λ�������"������"��a^b^a = a^a^b = b��������ֵ����λ���㣬����������ֵ��ȣ�����Ϊ��һ��ֵ����������·������������ a b ֵ�� 

nums:        a     a     b     b     c     c
x:     0     a     0     b     0     c     0

nums:        a     a     b     c     b     d     d  
x:     0     a     0     b    b^c    c    c^d    c
*/
