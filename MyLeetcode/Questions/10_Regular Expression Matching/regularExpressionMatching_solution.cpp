class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty(); //若p为空，若s也为空，返回true，反之返回false
        if (p.size() == 1) { // 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') { //若p的第二个字符不为*，
            if (s.empty()) return false; // 若此时s为空返回false，
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); //否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配 
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) { // 若p的第二个字符为*，若s不为空且首字符匹配， 
            if (isMatch(s, p.substr(2))) return true; // 调用递归函数匹配s和去掉前两个字符的p(*代表0 preceding情况)，若匹配返回true，
            s = s.substr(1); // 否则s去掉首字母  
        }
        return isMatch(s, p.substr(2)); // 返回调用递归函数匹配s和去掉前两个字符的p的结果 
    }
};

//'.'的处理很简单，只用在判断两个数是否相等上
/* 
理解处理 s="aa" 以及 p="a*" 的过程：
    isMatch("aa", "") --> s = "a", p = "a*"
    isMatch("a", "a*")  （注：这里是*代表1 preceding.先在while判断首元素是否相等isMatch("a", ""),然后再去掉s首字母） 
    isMatch("a", "") --> s = "", p = "a*" 
    isMatch("","") --> return true
所以处理*代表任意个preceding的方法就是：
1.两个两个处理（局部才可以递归；两个就有preceding） 
2.s左边元素逐一舍去，保证舍去后首元素相等，
3.*代表1 preceding情况 
*/ 
