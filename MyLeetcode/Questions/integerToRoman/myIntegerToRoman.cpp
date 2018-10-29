#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<char> c;
        int x = 0;
        int d = 10000;
        map<int, string> m, m4, m9;
        
        m.insert(make_pair(1000, "M"));
        m.insert(make_pair(100, "C"));
        m.insert(make_pair(10, "X"));
        m.insert(make_pair(1, "I"));
        m.insert(make_pair(500, "D"));
        m.insert(make_pair(50, "L"));
        m.insert(make_pair(5, "V"));
        
        m4.insert(make_pair(1000, "CD"));
        m4.insert(make_pair(100, "XL"));
        m4.insert(make_pair(10, "IV"));
        
        m9.insert(make_pair(1000, "CM"));
        m9.insert(make_pair(100, "XC"));
        m9.insert(make_pair(10, "IX"));
        
        
        while(num!=0) {
        	x = (num - x * d)/(d/10);
        	d = d/10;
        	
        	if (x==4) c.push_back(m4[d]);
			else if (x==9) c.push_back(m9[d]);
			else if (x<5) {
			    for (int i=0;i<x;i++) c.push_back(m[d]);
			}
			else {
				c.push_back(m[d]);
				for (int i=5;i<x;i++) c.push_back(m[5*d]);
			}
		}
		// ½«vector×ª»»Îªstring
		string s;
		for (int i=0;i<c.size();i++) {
			s[i] = c[i];
		} 
		return s;
	}
		
};

int main() {
	Solution solution;
	
	int input = 3;
	cout << solution.intToRoman(input) << endl;

	return 0;
} 
