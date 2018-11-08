class Solution {
public:
    int trap(int A[], int n) {
        int *max_left = new int[n](); //  
        int *max_right = new int[n]();
        
        for (int i = 1; i < n; i++) { // 左右扫描放在一个for循环里完成 
            max_left[i] = max(max_left[i - 1], A[i - 1]);
            max_right[n - 1 - i] = max(max_right[n - i], A[n - i]);
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int height = min(max_left[i], max_right[i]);
            if (height > A[i]) {
                sum += height - A[i];
            }
        }
        
        delete[] max_left;
        delete[] max_right;
        return sum;
    }
};


/* 总的思路还是十分清晰的，至少我一下就能想到。但是弱项在：
1.遍历数组，找出每个元素右边/左边的最大值-->从左往右，找出元素左边最大值；从右往左，找出元素右边最大值 
2.可以对数组进行值初始化，方法就是：在大小之后添加一对空括号。
*/ 
