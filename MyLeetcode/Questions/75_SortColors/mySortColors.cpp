/*
��������ֱ���޸�ԭ���ݣ� 
��Ҫɨ������������ɨ��һ�� �����ɫ�� 
*/ 

class Solution {
public:
	void sortColors(int A[], int n) {
		int counts[3] = {0}; //��¼ÿ����ɫ���ֵĴ��� 
		
		for (int i=0; i<n; i++) {
			counts[A[i]]++;
		}
		
		for (int i=0, index = 0; i<3; i++) { //index����ʹ�� 
			for (int j=0; j<couts[i]; j++) {
				A[index++] = i;
			}
		}
		
	}
};
