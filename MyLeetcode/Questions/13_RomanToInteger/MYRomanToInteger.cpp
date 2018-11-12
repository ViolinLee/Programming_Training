#include <iostream>
#include <map>
#include <string.h>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
    	if (s.size()<=0) return 0; // ����û�뵽��� 
        map<char, int> m = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        
        int res;
        char prev = s[0];
        string s_(s.begin()+1, s.end());
        for (auto &cur:s_) {
        	if (m[prev] >= m[cur]) res += m[prev]; 
			else res += -m[prev];
        	
        	prev = cur;
		}
		string::iterator s_lastITR = s.end() - 1;
		res += m[*s_lastITR]; // �����ַ���ץס�����һ�����ض��Ǽ� 
		
		return res;
    }
};

int main() {
	Solution solution;
	string input = "MCMXCIV";
	
	cout << solution.romanToInt(input);
	return 0;
}

/*
����+prev������+cur��+prev���Ա�֤prev������ȷ����Ϊprev��cur��֪��+cur���ܱ�֤cur������ȷ�����ܺ���Ҫ��ȥ����prev 
*/ 

