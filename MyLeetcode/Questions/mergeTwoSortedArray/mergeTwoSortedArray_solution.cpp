// 最直接，而然需要冗长且需要申请新变量空间 
class Solution1 {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m <= 0 && n <= 0) return;
        int a = 0, b = 0;
        int C[m + n];
        for (int i = 0; i < m + n; ++i) {
            if (a < m && b < n) {
                if (A[a] < B[b]) {
                    C[i] = A[a];
                    ++a;
                }
                else {
                    C[i] = B[b];
                    ++b;
                }
            }
            else if (a < m && b >= n) {
                C[i] = A[a];
                ++a;
            }
            else if (a >= m && b < n) {
                C[i] = B[b];
                ++b;
            }
            else return;
        }
        for (int i = 0; i < m + n; ++i) A[i] = C[i];
    }
};

// 简洁巧妙
class Solution2 {
public:
	void merge(int A[], int m, int B[], int n) {
		int ia = m-1, ib = n-1, icur = m+n-1;
		while(ia >= 0 && ib >= 0) 
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
			
		while(ib >= 0) 
		    A[icur--] = B[ib];
	}
	
};

 
