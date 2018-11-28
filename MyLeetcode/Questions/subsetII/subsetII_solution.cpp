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
/*̫�����ˣ� 
������last����¼��һ����������֣�Ȼ���ж���ǰ�����ֺ�������Ƿ���ͬ:
    ����ͬ����ѭ�����Ǵ�0����ǰ�Ӽ��ĸ���;
    ����ͬ�������Ӽ�������ȥ֮ǰѭ��ʱ�Ӽ��ĸ������������ѭ���������Ͳ�������ظ���.
*/



class Solution { //JUST DOIT 
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //������Ȼ��dfsÿ��Ԫ��ѡ���߲�ѡ�����Ҷ�ӽڵ�������н�
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
        firstSame++; //firstSame�ǵ�һ����S[iend]��ͬ���ֵ�λ��
        int sameNum = iend - firstSame;//��S[iend]��ͬ���ֵĸ���(���Լ�)
        if(sameNum == 0 ||
            (tmpres.size() >= sameNum && tmpres[tmpres.size() - sameNum] == S[iend])) //tmpres.size() >= sameNumȷ��tmpres[tmpres.size() - sameNum]������ 
        {
            //ѡ��S[iend]
            tmpres.push_back(S[iend]);
            dfs(S, iend+1, tmpres);
            tmpres.pop_back();
        }
        //��ѡ��S[iend]
        dfs(S, iend+1, tmpres);
    }
};
