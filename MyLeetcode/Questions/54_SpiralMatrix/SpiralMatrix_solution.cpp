class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2; // �������㹫ʽ 
        
        int p = m, q = n; // p, q���ڱ�ʾ�������������size 
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) { // ÿ��loop���ĸ�for����ÿ������������ 
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;  // ��p����qΪ1ʱ����ʾ���һ����ֻ��һ�л���һ��
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};


class Solution { // �Ƽ��Ľⷨ: �������� --> �������������� 
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if (++up > down) break; // ���break�������ܹؼ� 
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};


