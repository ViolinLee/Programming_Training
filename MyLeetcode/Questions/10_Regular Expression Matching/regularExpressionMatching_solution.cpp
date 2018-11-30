class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty(); //��pΪ�գ���sҲΪ�գ�����true����֮����false
        if (p.size() == 1) { // ��p�ĳ���Ϊ1����s����ҲΪ1������ͬ����pΪ'.'�򷵻�true����֮����false
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') { //��p�ĵڶ����ַ���Ϊ*��
            if (s.empty()) return false; // ����ʱsΪ�շ���false��
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); //�����ж����ַ��Ƿ�ƥ�䣬�ҴӸ��Եĵڶ����ַ���ʼ���õݹ麯��ƥ�� 
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) { // ��p�ĵڶ����ַ�Ϊ*����s��Ϊ�������ַ�ƥ�䣬 
            if (isMatch(s, p.substr(2))) return true; // ���õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p(*����0 preceding���)����ƥ�䷵��true��
            s = s.substr(1); // ����sȥ������ĸ  
        }
        return isMatch(s, p.substr(2)); // ���ص��õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p�Ľ�� 
    }
};

//'.'�Ĵ���ܼ򵥣�ֻ�����ж��������Ƿ������
/* 
��⴦�� s="aa" �Լ� p="a*" �Ĺ��̣�
    isMatch("aa", "") --> s = "a", p = "a*"
    isMatch("a", "a*")  ��ע��������*����1 preceding.����while�ж���Ԫ���Ƿ����isMatch("a", ""),Ȼ����ȥ��s����ĸ�� 
    isMatch("a", "") --> s = "", p = "a*" 
    isMatch("","") --> return true
���Դ���*���������preceding�ķ������ǣ�
1.�������������ֲ��ſ��Եݹ飻��������preceding�� 
2.s���Ԫ����һ��ȥ����֤��ȥ����Ԫ����ȣ�
3.*����1 preceding��� 
*/ 
