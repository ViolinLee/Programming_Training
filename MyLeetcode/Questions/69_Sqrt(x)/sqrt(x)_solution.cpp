class Solution { //���������� 
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {  // �������������1.��ʼright�����������ҵ�ֵ��2.right = mid��3.return right - 1 
            int mid = left + (right - left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};

//ע������ʹ�� if (x / mid >= mid) ? ��ʹ�� if (mid * mid >= x) ���������


class Solution { // ţ�ٵ����� 
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




