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
// 注：直接赋值不会影响 A 中未比较的元素！ 
// 因为在每次赋值时，必定有 ++pos <= i+1 （二者初值均为0，i每次loop加1；pos则不一定加1） 
