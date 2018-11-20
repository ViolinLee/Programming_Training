class Solution { //暴力匹配 
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  //如果子字符串为空，则返回0 
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;  //如果子字符串长度大于母字符串长度，则返回-1 
        for (int i = 0; i <= m - n; ++i) { //并不需要遍历整个母字符串 
            int j = 0;
            for (j = 0; j < n; ++j) { //对于每一个字符，遍历一遍子字符串
                if (haystack[i + j] != needle[j]) break; //逐个字符对应比较，若对应位置有不等，则跳出循环
            }
            if (j == n) return i; //若一直都没有跳出循环，则说明存在子字符串，则返回起始位置   
        }
        return -1;
    }
}; 
