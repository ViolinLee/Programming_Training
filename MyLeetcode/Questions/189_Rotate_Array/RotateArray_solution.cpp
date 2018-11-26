class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> t = nums; // 复制nums数组，空间复杂度为O(n) 
		for (int i = o; i < nums.size(); ++i) {
			nums[(i + k) % nums.size()] = t[i]; // 利用映射关系 
		}
	} 
};

class Solution { // 解法二使用解法一的思想(映射关系),但空间复杂度为O(1) 
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0) return;
		int n = nums.size(), start = 0, i = 0, cur = nums[i], cnt = 0;
		while(cnt++ < n) { // 7个数则有7次替换操作 
			i = (i + k) % n; // i映射为i的替换位置 
			int t = nums[i]; // 中间变量存储i的替换位置对应的值 
			nums[i] = cur; // 替换 
			if (i == start) { // 若i的替换位置为最初的i(替换结束？) 不理解... 
				++start; ++i;
				cur = nums[i];
			} else {
				cur = t; // cur存储新的用于替换的值 
			}
		}
 	}
};

class Solution { // 技巧性
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution { // 类似我的思路（其实也是rotate list的思路）
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

class Solution { // 解法五，不理解...
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
