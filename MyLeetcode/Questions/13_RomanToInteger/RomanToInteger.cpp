#include <iostream>
#include <map>
#include <string.h>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        
        int res;
        char cur = s[0];
        string s_(s.begin()+1, s.end());
        for (auto &next:s_) {
        	if (m[cur] >= m[next]) res += m[cur];
			else res += -m[cur];
        	
        	cur = next;
		}
		string::iterator s_lastITR = s.end() - 1;
		res += m[*s_lastITR];
		
		return res;
    }
};

int main() {
	Solution solution;
	string input = "MCMXCIV";
	
	cout << solution.romanToInt(input);
	return 0;
}



