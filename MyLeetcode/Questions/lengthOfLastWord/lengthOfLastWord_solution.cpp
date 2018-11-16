class Solution {
public:
    int lengthOfLastWord(const char *s) { // ���ҵ��������������ո���� 
        int len = strlen(s);
        int left = 0;
        int right = len - 1;
        int count = 0;
        while (s[left] == ' ') ++left; // ������while�������ո�; ע��char *s ������ʽ������ַ��������治������з� 
        while (s[right] == ' ') --right;
        for (int i = left; i <= right; ++i) {
            if (s[i] == ' ') count = 0;
            else ++count;
        }
        return count;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) { // 
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (i != 0 && s[i - 1] == ' ') res = 1;  
                else ++res; // i ==0 || s[i-1] != '' 
            }
        }
        return res;
    }
};



class Solution { // ��β��ͷ 
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1, res = 0;
        while (right >= 0 && s[right] == ' ') --right;
        while (right >= 0 && s[right] != ' ' ) { // ץס���Ȿ�� 
            --right; 
            ++res;
        }
        return res;
    }
};

