class Solution { //二分搜索法 
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {  // 用了这个条件则：1.初始right不能是所查找的值；2.right = mid；3.return right - 1 
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};

//注：条件使用 if (x / mid >= mid) ? 若使用 if (mid * mid >= x) 可能溢出！


class Solution { // 牛顿迭代法 
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};




