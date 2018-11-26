class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> t = nums; // ����nums���飬�ռ临�Ӷ�ΪO(n) 
		for (int i = o; i < nums.size(); ++i) {
			nums[(i + k) % nums.size()] = t[i]; // ����ӳ���ϵ 
		}
	} 
};

class Solution { // �ⷨ��ʹ�ýⷨһ��˼��(ӳ���ϵ),���ռ临�Ӷ�ΪO(1) 
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0) return;
		int n = nums.size(), start = 0, i = 0, cur = nums[i], cnt = 0;
		while(cnt++ < n) { // 7��������7���滻���� 
			i = (i + k) % n; // iӳ��Ϊi���滻λ�� 
			int t = nums[i]; // �м�����洢i���滻λ�ö�Ӧ��ֵ 
			nums[i] = cur; // �滻 
			if (i == start) { // ��i���滻λ��Ϊ�����i(�滻������) �����... 
				++start; ++i;
				cur = nums[i];
			} else {
				cur = t; // cur�洢�µ������滻��ֵ 
			}
		}
 	}
};

class Solution { // ������
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution { // �����ҵ�˼·����ʵҲ��rotate list��˼·��
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        for (int i = 0; i < n - k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

class Solution { // �ⷨ�壬�����...
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};
