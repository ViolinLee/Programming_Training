#include<stdio.h>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	int flag = 1;
    	int integer = 0; 
    	int length = str.length();
    	
    	int y = (int)str[0];
    	
        if (y >9 ) flag = 0;
        else if (' '==str[0]) { integer = myAtoi(str.substr(1, length-1));}
        else if (str[0]=='-') { integer = -myAtoi(str.substr(1, length-1));}
        else {
        	int str_length = str.length();
        	for (int i=0;i<str_length;i++){
        		if ((int)str[i] < 9)
        			integer = integer * 10 + (int)str[i];
        		else break;
			}
		}
        
        return integer;
    }
};

int main() {
	Solution s;
	
	string s1 = "520";
	string s2 = "    -520";
	string s3 = "520 Hello";
	string s4 = "Hello 520";
	string s5 = "-91283472332";
	
	printf("%s", s.myAtoi(s1));
	printf("%s", s.myAtoi(s2));
	printf("%s", s.myAtoi(s3));
	printf("%s", s.myAtoi(s4));
	printf("%s", s.myAtoi(s5));
	
	return 0;
}


/* 不通过
1.字符串中的数字类字符怎么和整型0~9比较？例子： str[i] > '9'
   我在这里使用 (int)str[i] > 9 不够直接。 
2. 将数字字符串转化为数字？
   我想到了用 for 循环访问数字，再用 integer = integer * 10 + (int)str[i]; 
   Solution的解法也是 for 循环，里面则是 num = num * 10 + str[i] - '0';
   所以思路是正确的，就是编程上由瑕疵。 
3.细节1：情况分类的准确性
    1）不规则输入，但是有效；"-3924x8fc"-->-3924; "+413" --> 413
	2）无效格式： "++c", "++1" 注意后者 
	3）数据溢出： "2147483648" 和 "-2147483649" 

4.细节2：数据溢出处理 
    关键：怎么判断数据溢出
	处理：输出临界值 INT_MIN 还是 INT_MAX? 
