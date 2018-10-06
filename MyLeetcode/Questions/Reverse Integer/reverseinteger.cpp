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
���ã�
1.�κγ��ȵ�������10ȡģ�����Ϊ��������λ�ϵ�����
2. ��������10���õ�������Ϊʮλ����λ��ǧλ......��
*/ 
