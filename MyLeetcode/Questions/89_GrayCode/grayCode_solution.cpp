// Binary to grey code
class Solution { //������Ͷ�����֮���ת�� 
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i); // ����+��� 
        }
        return res;
    }
};

// Mirror arrangement
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};

// Direct arrangement 
class Solution { // û��ȥ��� 
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        int len = pow(2, n);
        for (int i = 1; i < len; ++i) {
            int pre = res.back();
            if (i % 2 == 1) {
                pre = (pre & (len - 2)) | ((~pre) & 1);
            } else {
                int cnt = 1, t = pre;
                while ((t & 1) != 1) {
                    ++cnt;
                    t >>= 1;
                }
                if ((pre & (1 << cnt)) == 0) pre |= (1 << cnt);
                else pre &= ~(1 << cnt);
            }
            res.push_back(pre);
        }
        return res;
    }
};

/******************************ǰ�����ֽⷨ��Ҫ֪��gray code����**********************************/
class Solution { // �ݹ� 
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> s; // ʹ��set���ݽṹ�����Ѳ����Ľ�� 
        helper(n, s, 0, res);
        return res;
    }
    void helper(int n, unordered_set<int>& s, int out, vector<int>& res) {
        if (!s.count(out)) {
            s.insert(out);
            res.push_back(out);
        }
        for (int i = 0; i < n; ++i) { // ����out������ÿһλ 
            int t = out;
            if ((t & (1 << i)) == 0) t |= (1 << i); // if-elseȡ���� 
            else t &= ~(1 << i);
            if (s.count(t)) continue; // ��û����set���ֹ��� 
            helper(n, s, t, res); // �����set��res�� 
            break;
        }
    }
};

class Solution { // ��������Ȼ��Ҫstack���� 
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        unordered_set<int> s;
        stack<int> st;
        st.push(0);
        s.insert(0);
        while (!st.empty()) {
            int t = st.top(); st.pop();
            for (int i = 0; i < n; ++i) {
                int k = t;
                if ((k & (1 << i)) == 0) k |= (1 << i);
                else k &= ~(1 << i);
                if (s.count(k)) continue;
                s.insert(k);
                st.push(k);
                res.push_back(k);
                break;
            }
        }
        return res;
    }
};
 
