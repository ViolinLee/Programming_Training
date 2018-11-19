class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false)); // ������־���󣨰�������������ֵ�йص�λ�ã� 
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false; // �ó�����������Ӹ��� 
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        
        return true;
    }
};

/* ע����־������· 
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        ...c = matrix[i][j]...  // i��j�г���c 
        rowFlag[i][c] // ��Ҫ���i�г���c --> rowFlag[i][c] = true; (��Ϊ����c֮�⻹�������������������һά��: rowFlag[i] = true;)
        colFlag[c][j]
    }
}


*/ 
