class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		
		vector<bool> row(m, false); // ��Ǹ����Ƿ���� 0 
		vector<bool> col(n, false); // ��Ǹ����Ƿ���� 0
		
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0){    //  
					row[i] = col[j] = true; 
				}
			}
		} 
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
			    fill(&matrix[i][0], &matrix[i][0] + n, 0); // �е�Ԫ�����ڴ������������ڵģ����Ե���fill 
		}
		for (size_t j = 0; j < n; ++j) {
			if (col[j]) {
				for (size_t i = 0; i < m; ++i) { // �е�Ԫ�����ڴ��в����������ڵģ�ֻ�ܽ���Ƕ�׵�for�������б��� 
					matrix[i][j] = 0;
				}
			}
		}
	}
	
	
};

// �����ռ临�Ӷ�-->�����¿ռ� 
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) colZero = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) rowZero = true;
        } 
        for (int i = 1; i < m; ++i) { // ��һ��Ƕ�׵�for���ڼ�¼ 
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) { // �ڶ���Ƕ�׵�for���ڸ���ֵ 
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

/*
1.��������һ�ַ����������ⲻ��Ƕ��for��matrixÿһ��Ԫ�صı��� 
2.��������һ�ַ��������̶��ǡ���¼ + ��ֵ����
    O(m*n)ÿ�μ�¼�͸��£�
	O(m+n)�ȼ�¼����ڸ��£����������������ڼ�¼��
	O(1)�ȼ�¼����ٸ��£�����¼�������ϡ� 
3. fill(vec.begin(), vec.end(), val);
*/ 

