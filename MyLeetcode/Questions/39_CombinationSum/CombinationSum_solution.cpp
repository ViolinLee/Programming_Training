class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res; //res������ս��
        vector<int> out;//out����м���   
        sort(candidates.begin(), candidates.end()); // ������ֱ���Ͼ�Ӧ����sort 
        combinationSumDFS(candidates, target, 0, out, res); // ��дһ���ݹ麯�����ӿ�+������ݹ����res�� 
        return res;
    }
    void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> out, vector<vector<int>> &res) { 
        if (target < 0) return; // ��֦ 
        else if (target == 0) {res.push_back(out); return;} // �ҵ�һ���Ϸ��� 
        for (int i = start; i < candidates.size(); ++i) { // ��չ״̬��for�����ٵݹ�......forʵ���˶�path�ݹ� 
            out.push_back(candidates[i]); // ִ����չ���� 
            combinationSumDFS(candidates, target - candidates[i], i, out, res); // target��̬�ģ���permutation�ĵݹ�̫���� 
            out.pop_back(); // �������� 
        }
    }
};
/* 
1. combinationSumDFS(candidates, target - candidates[i], i, out, res); ע�������������i����ʾ�����ظ�ʹ���Լ� 
2. ע�⵽ for(int i = start; i < candidates.size(); ++i)
          for�����combinationSumDFS(candidates, target - candidates[i], i, out, res);��start��i��ʼ
    ���Ի�ý������ǣ�
	[
    [2,2,2,2],
    [2,3,3],
    [3,5]
    ] 
    ���Կ�������2...
	        ����3... 
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


//�ݹ�ⷨ 
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


