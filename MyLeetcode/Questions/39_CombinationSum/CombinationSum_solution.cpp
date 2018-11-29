class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res; //res存放最终结果
        vector<int> out;//out存放中间结果   
        sort(candidates.begin(), candidates.end()); // 这类题直觉上就应该先sort 
        combinationSumDFS(candidates, target, 0, out, res); // 另写一个递归函数（接口+将结果递归放入res） 
        return res;
    }
    void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out, vector<vector<int>> &res) { 
        if (target < 0) return; // 剪枝 
        else if (target == 0) {res.push_back(out); return;} // 找到一个合法解 
        for (int i = start; i < candidates.size(); ++i) { // 扩展状态；for里面再递归......for实现了多path递归 
            out.push_back(candidates[i]); // 执行扩展动作 
            combinationSumDFS(candidates, target - candidates[i], i, out, res); // target动态的；和permutation的递归太像了 
            out.pop_back(); // 撤销动作 
        }
    }
};
/* 
1. combinationSumDFS(candidates, target - candidates[i], i, out, res); 注意这里第三项是i，表示可以重复使用自己 
2. 注意到 for(int i = start; i < candidates.size(); ++i)
          for里面的combinationSumDFS(candidates, target - candidates[i], i, out, res);的start从i开始
    所以获得结果组合是：
	[
    [2,2,2,2],
    [2,3,3],
    [3,5]
    ] 
    可以看到先找2...
	        再找3... 
*/ 




class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            else if (candidates[i] == target) {res.push_back({candidates[i]}); continue;}
            vector<int> vec = vector<int>(candidates.begin() + i, candidates.end());
            vector<vector<int>> tmp = combinationSum(vec, target - candidates[i]);
            for (auto a : tmp) {
                a.insert(a.begin(), candidates[i]);
                res.push_back(a);
            }
        }
        return res;
    }
};


//递归解法 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<vector<int>>> dp;
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= target; ++i) {
            vector<vector<int>> cur;
            for (int j = 0; j < candidates.size(); ++j) {
                if (candidates[j] > i) break;
                else if (candidates[j] == i) {cur.push_back({candidates[j]}); continue;}
                for (auto a : dp[i - candidates[j] - 1]) {
                    if (candidates[j] > a[0]) continue;
                    a.insert(a.begin(), candidates[j]);
                    cur.push_back(a);
                }
            }
            dp.push_back(cur);
        }
        return dp[target - 1];
    }
};


