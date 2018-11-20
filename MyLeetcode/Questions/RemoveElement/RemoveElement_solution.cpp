class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i]; //把当前值nums[i]覆盖计数变量的位置num[res],然后计数变量加1
        }
        return res;
    }
};

/*
和unique的效果一致，把不重复的元素连续地搬运至最前，原数组的尾巴部分还留着 
只不过unique返回指针；这里返回新数组长度（nums.begin() + res -1) 那就是和unique效果完全一致啦 
*/ 
