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
        else if (target == 0) res.push_back(out); // ����push_back�����ֱ�� return;
        else {
            for (int i = start; i < num.size(); ++i) {
                if (i > start && num[i] == num[i - 1]) continue; // �����ظ�ʹ��(ֵ��ͬ��������ͬһ����)
                out.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, out, res); // �����ظ�ʹ��(�Լ�����)
                out.pop_back();
            }
        }
    }
};

/*
combination sum һ�⣬���������е��������ظ�ʹ�á����Ȿ����û�����𣬶�����ʹ�õݹ飬��΢�޸���������ʵ�֡� 
*/
