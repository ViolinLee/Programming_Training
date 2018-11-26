class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
    }
};


/*我的思路 
1.给的容器是vector，用什么操作实现单个元素的旋转？如果多个元素旋转呢？
push_back, insert(nums.begin(), ###), for(k次) （答案解法四用的是push_back, erase，for(n-k次)） 
*/
