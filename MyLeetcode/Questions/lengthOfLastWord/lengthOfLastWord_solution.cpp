class Solution {
public:
    int lengthOfLastWord(const char *s) { // 比我的做法多了消除空格操作 
        int len = strlen(s);
        int left = 0;
        int right = len - 1;
        int count = 0;
        while (s[left] == ' ') ++left; // 用两个while来消除空格; 注：char *s 这种形式传入的字符串，后面不会带换行符 
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



class Solution { // 从尾向头 
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1, res = 0;
        while (right >= 0 && s[right] == ' ') --right;
        while (right >= 0 && s[right] != ' ' ) { // 抓住问题本质 
            --right; 
            ++res;
        }
        return res;
    }
};

