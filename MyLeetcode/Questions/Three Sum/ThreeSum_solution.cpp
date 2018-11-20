// 主流的解法：k-sum，sort，k-2次循环，最内层左右夹逼

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		vector<vector<int>> result;
		if (num.size() < 3) return result;
		
		sort(num.begin(), num.end()); // sort(.begin(), .end()) 
		const int target = 0;
		
		auto last = num.end();
		for (auto i = num.begin(); i < last-2; ++i) {
			auto j = i + 1; // j从i+1开始 
			if (i > num.begin() && *i == *(i-1)) continue;
			auto k = last - 1;
			while(j < k) {
				if (*i + *j + *k < target) {
					++j;
					while(*j == *(j - 1) && j < k) ++j; //跳过重复数 
				} else if (*i + *j + *k > target) {
					--k;
					while(*k == *(k + 1) && j < k) --k;
				} else {
					result.push_back({ *i, *j, *k });
					++j;
					--k;
					while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j; // 我认为 ++j; --k; 亦可 
				}
			}
		}
		return result;
 	}
};

/*
注：为什么j从i+1开始；i指的是确定的第一个元素，在这一轮，i和另外两个数的三数组合都会遍历过。
    因此，下一轮不再包含i。 
*/ 
