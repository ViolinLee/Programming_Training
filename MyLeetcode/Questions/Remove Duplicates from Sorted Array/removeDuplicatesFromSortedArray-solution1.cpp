class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if (n<=1) return n;
        
        int pos=0;
        for(int i=0; i<n-1; i++){
            if (A[i]!=A[i+1]){
                A[++pos] = A[i+1];
            }
        }
        return pos+1;
    }
};
// ע��ֱ�Ӹ�ֵ����Ӱ�� A ��δ�Ƚϵ�Ԫ�أ� 
// ��Ϊ��ÿ�θ�ֵʱ���ض��� ++pos <= i+1 �����߳�ֵ��Ϊ0��iÿ��loop��1��pos��һ����1�� 
