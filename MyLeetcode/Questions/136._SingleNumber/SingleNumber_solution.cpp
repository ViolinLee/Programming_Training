/*
������һ���ǳ��򵥵��⣬����������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
ʹ�ò��������򷽷���Ҳ����ʹ��map���ݽṹ��
�����������ץס"every element appears twice except for one",����ʹ��bit operation��
���������������ÿ����ͬ���ֵ�0�������ʣ�µ����־����Ǹ�ֻ��1�ε����֡� 
*/ 

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int res = 0; // 0����κ��������ԭ�� 
		for (auto num : nums) res ^= num;
		return res;
	}
};
