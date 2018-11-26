class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || (s.size()) > 1 && s[0] == '0') return 0;
		vector<int> dp(s.size() + 1, 0); // dp���ȣ� 
		dp[0] = 1; //dp��һ��Ϊ1��
		for (int i = 1; i < dp.size(); ++i) {
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1]; // �൱��dp[i] += dp[i-1] 
			if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) { //dp[i] += dp[i-2]  
				dp[i] += dp[i - 2];
			}
		}
		return dp.back();
    }
};
/* 
���ƹ�ʽ dp[i] = dp[i-1] + dp[i-2]
��ʵ�ϣ�dp[0]û�����壬ֻ��Ϊ�˹�ʽ����
��Ϊsize==1����size==2�������ȷ���ģ�����size==3��ʼ����ʵ��ʹ�ù�ʽ��Ϊ��size==2Ҳ��Ӧ�ù�ʽ������������dp[0] = 1 
0  1 ����s.empty����0�� 
1  1
2  2
3  3 (s[3])
*/ 
