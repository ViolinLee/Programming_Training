#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
// O(n^2)��O(1)
class Solution1 {
public:
    string intToRoman(int num) {
        string res = "";  
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; // ֻʹ�ã������ַ� --> ��������������� 
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) { // �����value��ѡȡ "1XXX" 
            int x = num / value[n];
            // �Ը�λ���з������ۣ�0-3,4,5-8,9
			// 4 �� 9 ���������Ҫѭ�� 
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

// O(n)��O(1) ̰���㷨������һ������ÿ��ͨ������ҳ� "��ǰ������" ����ȥ�ټ������
class Solution2 {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; // ʹ�ã������ַ� + 4XXX��9XXX������ַ� --> ��������ٷ�������  
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) { // ע����ѭ��������val�����εݼ���ֵ 
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

// O(1)��O(1) ȡ�̷��� 
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
ע���������� 1437����������Ϊ MCDXXXVII��
    ���ǲ��ѷ��֣�ǧλ����λ��ʮλ�͸�λ�ϵ����ֱ����������ֱ�ʾ�ˡ� 
	1000 - M, 400 - CD, 30 - XXX, 7 - VII��
	��������Ҫ���ľ����� "ȡ�̷�" �ֱ���ȡ����λ�ϵ����֣�Ȼ��ֱ��ʾ������ 
��ȡ��λ����num / 1000 , (num % 1000) / 100 , (num % 100) / 10 , (num % 10) / 1 -->  /����ȡ���λ   %���������λ 
string ������ "+" 
*/ 
