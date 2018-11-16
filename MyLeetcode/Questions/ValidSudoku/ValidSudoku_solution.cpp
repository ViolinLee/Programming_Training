class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false)); // 三个标志矩阵（把数藏在与数的值有关的位置） 
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false; // 用除号巧妙遍历子格子 
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        
        return true;
    }
};

/* 注：标志矩阵套路 
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        ...matrix[i][j]...
        rowFlag[i][c] 
        colFlag[c][j]
    }
}


*/ 
