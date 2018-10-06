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


/* ��ͨ��
1.�ַ����е��������ַ���ô������0~9�Ƚϣ����ӣ� str[i] > '9'
   ��������ʹ�� (int)str[i] > 9 ����ֱ�ӡ� 
2. �������ַ���ת��Ϊ���֣�
   ���뵽���� for ѭ���������֣����� integer = integer * 10 + (int)str[i]; 
   Solution�ĽⷨҲ�� for ѭ������������ num = num * 10 + str[i] - '0';
   ����˼·����ȷ�ģ����Ǳ������覴á� 
3.ϸ��1����������׼ȷ��
    1�����������룬������Ч��"-3924x8fc"-->-3924; "+413" --> 413
	2����Ч��ʽ�� "++c", "++1" ע����� 
	3����������� "2147483648" �� "-2147483649" 

4.ϸ��2������������� 
    �ؼ�����ô�ж��������
	��������ٽ�ֵ INT_MIN ���� INT_MAX? 
