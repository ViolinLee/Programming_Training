/*
不管哪一种解法都是两层循环，内层行外层列，且列受行数影响，例如 j < n-1 
*/ 

class Solution1 { // 直接法，其实可以使用swap 
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) { // dimension/2 
            for (int j = i; j < n - 1 - i; ++j) { // 两层for循环 
                int tmp = matrix[i][j]; // 一个临时变量 
                matrix[i][j] = matrix[n - 1 - j][i]; // 下标的思路和访问顺序 
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) { // 对角线为轴翻转
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i) { // 中线上下翻转 
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};

class Solution3 { // 简洁 
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) { // 主对角线翻转 
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end()); // 竖直中线翻转 -> 可调用reverse 
        }
    }
};
