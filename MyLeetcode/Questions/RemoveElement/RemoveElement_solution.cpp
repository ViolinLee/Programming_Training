class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i]; //�ѵ�ǰֵnums[i]���Ǽ���������λ��num[res],Ȼ�����������1
        }
        return res;
    }
};

/*
��unique��Ч��һ�£��Ѳ��ظ���Ԫ�������ذ�������ǰ��ԭ�����β�Ͳ��ֻ����� 
ֻ����unique����ָ�룻���ﷵ�������鳤�ȣ�nums.begin() + res -1) �Ǿ��Ǻ�uniqueЧ����ȫһ���� 
*/ 
