#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
// O(n^2)，O(1)
class Solution1 {
public:
    string intToRoman(int num) {
        string res = "";  
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; // 只使用：基本字符 --> 下面代码多分类讨论 
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) { // 巧妙从value中选取 "1XXX" 
            int x = num / value[n];
            // 对各位进行分类讨论：0-3,4,5-8,9
			// 4 和 9 的情况不需要循环 
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } 
			else if (x == 4) res = res + roman[n] + roman[n - 1];
            else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            }
            else if (x == 9) res = res + roman[n] + roman[n - 2];
            num %= value[n];            
        }
        return res;
    }
};

// O(n)，O(1) 贪婪算法：建立一个数表，每次通过查表找出 "当前最大的数" ，减去再继续查表
class Solution2 {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; // 使用：基本字符 + 4XXX和9XXX的组合字符 --> 下面代码少分类讨论  
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) { // 注：外循环条件是val中依次递减的值 
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

// O(1)，O(1) 取商法！ 
class Solution3 {
public:
    string intToRoman(int num) {
        string res = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
    }
};

int main() {
	Solution1 solution;
	
	int input = 400;
	cout << solution.intToRoman(input) << endl;

	return 0;
} 

/*
注：例如整数 1437的罗马数字为 MCDXXXVII，
    我们不难发现，千位，百位，十位和个位上的数分别用罗马数字表示了。 
	1000 - M, 400 - CD, 30 - XXX, 7 - VII。
	所以我们要做的就是用 "取商法" 分别提取各个位上的数字，然后分别表示出来： 
提取各位数：num / 1000 , (num % 1000) / 100 , (num % 100) / 10 , (num % 10) / 1 -->  /：提取最高位   %：舍弃最高位 
string 操作符 "+" 
*/ 
