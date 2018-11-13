// 递归版本(深搜，增量构造法) 
class Solution {
public:
	vector<vector<int> > permute(vector<int>& num) {
		sort(num.begin(), num.end());
		
		vector<vector<int> > result;
		vector<int> path;  // 中间结果
		
		dfs(num, path, result);
		return result; 
	}
private:
	void dfs(const vector<int>& num, vector<int>& path, vector<vector<int> >& result) {
		if (path.size() == num.size()) {   // 收敛条件
		    result.push_back(path);
		    return;
		}
		// 扩展状态
		for (auto i : num) {
			// 查找 i 是否在 path 中出现过
			auto pos = find(path.begin(), path.end(), i);
			
			if (pos == path.end()) {
				path.push_back(i); // 进入dfs前，改变path长度 
				dfs(num, path, result);   
				path.pop_back(); // dfs = (push_back --> dfs --> pop_back) 进入dfs出来后，path长度不改变  
			}
		} 
	}
}; 

// 这个解法有点难转弯。。。 
