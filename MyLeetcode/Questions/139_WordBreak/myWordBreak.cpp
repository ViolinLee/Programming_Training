class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
};

/*
�ҵ�˼·���ݹ�
1.����wordDict��ÿȡһ��word������һ��s�������ڶ��ٸ�WORD1����¼λ�ã��������ڣ�����false�� 
2.����ÿ��WORD1��ÿ�ν���ǰWORD1��������s��ɾ����
3.����ȡ��һ��word�������޸ĺ��s,�����ڶ��ٸ�WORD2����¼λ�ã��������ڣ�����false��
4.����ÿ��WORD2��ÿ�ν���ǰWORD2��������s��ɾ����
...
���������WORDn���Ҵ��ڣ��򷵻�True 

ע�����ַ�������û��������⣬�����Ƿֳ�k�κ�k>1�����γɵ�k+1���γɵ�k+1��word���ܴ�worddict���ҵ� 
*/
