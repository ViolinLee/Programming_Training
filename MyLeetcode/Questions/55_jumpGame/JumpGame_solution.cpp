class Solution1 { // ̰���㷨 
public:
	bool canJump(vector<int>& A) {
		nums = A.size();
		
		int reach = 1; // ��������������
		for (int i = 0; i < reach && reach < nums; ++i)
		    reach = max(reach, i + 1 + A[i]); // ��¼��A[i]���ܴﵽ������ 
		return reach >= nums; // ע��reach��1��ʼ; i��0��ʼ 
	}
}; 


class Solution2 { // ��̬�滮 
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1; //״̬ת�Ʒ��̣�ע��Hidden Information������Ϣf(0)=0; i>0�� 
            if (dp[i] < 0) return false;
        }
        return dp.back() >= 0;
    }
};
/*
1. f(i)�е�i>0;��Ϊ������������Ծһ�κ�����ʣ�ಽ���������� 
2.��ǰλ�õ�ʣ�ಽ��dp[i],����һ��λ�õ�ʣ�ಽ��dp[i-1]�Լ���һλ����������Զ����A[i]�йء�
������ֵ�Ľϴ�ֵ����������һλ�����ܴﵽ����Զ���롣��������ȥ1���͵õ����ﵱǰλ�õ�ʣ�ಽ����
������ĳһλ�õ�ʣ�ಽ��С����ʱ��֤�����ܵ�����һλ�ã��Լ��Ժ������λ�á� 
*/ 


