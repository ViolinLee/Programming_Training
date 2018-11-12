class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n+1, 0);
		
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; ++i) { // 对数列的每一个项 
			for (int k = 1; k <= i; ++k) f[i] += f[k-1] * f[i-k]; // 应用递推公式 
		}
		return f[n];
	}
};
