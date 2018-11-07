/*
计数排序，直接修改原数据； 
需要扫描两遍容器；扫描一遍 类别（颜色） 
*/ 

class Solution {
public:
	void sortColors(int A[], int n) {
		int counts[3] = {0}; //记录每个颜色出现的次数 
		
		for (int i=0; i<n; i++) {
			counts[A[i]]++;
		}
		
		for (int i=0, index = 0; i<3; i++) { //index巧妙使用 
			for (int j=0; j<couts[i]; j++) {
				A[index++] = i;
			}
		}
		
	}
};
