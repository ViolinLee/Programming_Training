#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.empty()) return ""; // ��strsΪ�յ�vector����һ��ֱ����str[0]�����
    	
        int min_size = strs[0].size();
        string res = "";
        
        for (auto str : strs) {
        	if (str.size() < min_size) min_size = str.size();
		}
		
		for (int i = 0; i < min_size; i++) { 
			char temp = strs[0][i];
			for ( auto str : strs) {
				if (str[i] == temp) continue;
				else return res; // ����ʹ��return��ǰ����Բ���Ҫ����Сstr���ȣ�������Ҫ���޸�(��Solution) 
			}
			res += temp;
		}
		
		return res;
    }
};

int main() {
	Solution solution;
	vector<string> s = {"dog","racecar","car"};
	
	string res = solution.longestCommonPrefix(s);
	
	cout << res << endl;
	
	return 0;
}

// ע��������Ԫ���±ꡢ�ڲ����vectorԪ�أ����ƽʱϰ�������෴�� 
