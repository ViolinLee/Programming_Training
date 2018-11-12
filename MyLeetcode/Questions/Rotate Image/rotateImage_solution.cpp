/*
������һ�ֽⷨ��������ѭ�����ڲ�������У�����������Ӱ�죬���� j < n-1 
*/ 

class Solution1 { // ֱ�ӷ�����ʵ����ʹ��swap 
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) { // dimension/2 
            for (int j = i; j < n - 1 - i; ++j) { // ����forѭ�� 
                int tmp = matrix[i][j]; // һ����ʱ���� 
                matrix[i][j] = matrix[n - 1 - j][i]; // �±��˼·�ͷ���˳�� 
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
        for (int i = 0; i < n - 1; ++i) { // �Խ���Ϊ�ᷭת
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i) { // �������·�ת 
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};

class Solution3 { // ��� 
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) { // ���Խ��߷�ת 
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end()); // ��ֱ���߷�ת -> �ɵ���reverse 
        }
    }
};
