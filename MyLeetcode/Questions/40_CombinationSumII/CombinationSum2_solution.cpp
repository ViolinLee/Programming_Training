class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(num.begin(), num.end());
        combinationSum2DFS(num, target, 0, out, res);
        return res;
    }
    void combinationSum2DFS(vector<int> &num, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) return;
        else if (target == 0) res.push_back(out); // 这里push_back后可以直接 return;
        else {
            for (int i = start; i < num.size(); ++i) {
                if (i > start && num[i] == num[i - 1]) continue; // 避免重复使用(值相同，但不是同一个数)
                out.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, out, res); // 避免重复使用(自己本身)
                out.pop_back();
            }
        }
    }
};

/*
combination sum 一题，给定数组中的数可以重复使用。两题本质上没有区别，都可以使用递归，稍微修改两处就能实现。 
*/
