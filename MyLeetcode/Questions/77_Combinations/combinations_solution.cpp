class Solution { // 递归版本 
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		vector<int> out;
		helper(n, k, 1, out, res);
		return res;
	}
	
	void helper(int n, int k, int level, vector<int>& out, vector<vector<int> >& res) { // 递归函数接口 
		if (out.size() = k) {res.push_back(out); return;} // 基
		for (int i = level; i <= n; ++i) {
			out.push_back(i);
			helper(n, k, i + 1, out, res);
			out.pop_back();
		} 
	}
};


