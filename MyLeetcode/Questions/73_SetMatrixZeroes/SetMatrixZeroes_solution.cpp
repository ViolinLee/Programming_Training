class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		
		vector<bool> row(m, false); // 标记该行是否存在 0 
		vector<bool> col(n, false); // 标记该列是否存在 0
		
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0){    //  
					row[i] = col[j] = true; 
				}
			}
		} 
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
			    fill(&matrix[i][0], &matrix[i][0] + n, 0); // 行的元素在内存中是连续存在的，可以调用fill 
		}
		for (size_t j = 0; j < n; ++j) {
			if (col[j]) {
				for (size_t i = 0; i < m; ++i) { // 列的元素在内存中不是连续存在的，只能借助嵌套的for对若干列遍历 
					matrix[i][j] = 0;
				}
			}
		}
	}
	
	
};

// 常数空间复杂度-->不起新空间 
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
        for (int i = 1; i < m; ++i) { // 第一个嵌套的for用于记录 
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) { // 第二个嵌套的for用于赋零值 
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
1.不管是哪一种方法，都避免不了嵌套for对matrix每一个元素的遍历 
2.无论是哪一种方法，流程都是“记录 + 赋值”；
    O(m*n)每次记录就更新；
	O(m+n)先记录最后在更新，开辟了新数组用于记录；
	O(1)先记录最后再更新，但记录在数组上。 
3. fill(vec.begin(), vec.end(), val);
*/ 

