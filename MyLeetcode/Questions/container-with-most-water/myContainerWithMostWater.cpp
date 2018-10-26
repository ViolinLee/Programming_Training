#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV = 0, left = 0, right = height.size() - 1;
        
		while(left < right) {
        	maxV = max(maxV, min(height[left], height[right]) * (right - left));
        	
        	if (height[left]<height[right]) left++;
        	else right--;
        	
		}
		return maxV;
    }
};

int main() {
	Solution solution;
	int s[] = {1,8,6,2,5,4,8,3,7};
	vector<int> v(begin(s), end(s)); // ���
	//  vector<int> v(s, s+9); // ͬ���Ϸ� 
	
	cout << solution.maxArea(v) << endl;
	
	// ��������ִ�н��һ��-->��������ڴ��������µ���Ϊ����ָ�룻cout << s ���Ǵ�ӡָ���ֵ 
	cout << s << endl;
	cout << begin(s) << endl;
	
	return 0;
}

/* ע������ֻ�뵽O(n^2)�Ľⷨ������ֱ��ѧϰsolution˼·��Ȼ���Լ�д 
solution����˼·��
    1.container ��ݼ���ÿ����һ�ο��һ����ÿ��ѭ��������ÿ��µ��������� 
    2.Ͱ��͵�һ��Ϊ��ݼ��ķ��򣨼����ǿ�ߵ�һ���ݼ�����һ�ε������ݻ��ض��������ϴε��ݻ��� 
*/ 
