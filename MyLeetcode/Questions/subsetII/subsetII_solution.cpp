class Solution { //Grandyang 
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        int size = 1, last = S[0];
        for (int i = 0; i < S.size(); ++i) {
            if (last != S[i]) {
                last = S[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};
/*太巧妙了！ 
我们用last来记录上一个处理的数字，然后判定当前的数字和上面的是否相同:
    若不同，则循环还是从0到当前子集的个数;
    若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了.
*/



class Solution { //JUST DOIT 
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
        res.clear();
        sort(S.begin(), S.end());
        vector<int>tmpres;
        dfs(S, 0, tmpres);
        return res;
    }
    void dfs(vector<int> &S, int iend, vector<int> &tmpres)
    {
        if(iend == S.size())
            {res.push_back(tmpres); return;}
        int firstSame = iend;
        while(firstSame >=0 && S[firstSame] == S[iend])firstSame--;
        firstSame++; //firstSame是第一个和S[iend]相同数字的位置
        int sameNum = iend - firstSame;//和S[iend]相同数字的个数(除自己)
        if(sameNum == 0 ||
            (tmpres.size() >= sameNum && tmpres[tmpres.size() - sameNum] == S[iend])) //tmpres.size() >= sameNum确保tmpres[tmpres.size() - sameNum]不出错 
        {
            //选择S[iend]
            tmpres.push_back(S[iend]);
            dfs(S, iend+1, tmpres);
            tmpres.pop_back();
        }
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};
