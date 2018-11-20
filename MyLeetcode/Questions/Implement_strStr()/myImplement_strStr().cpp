#include <string.h>
#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i < h-n+1; i++) { // 很正！因为没有必要遍历整个字符串 
        	if (haystack.substr(i, n) == needle) return i;
		}
		return -1;
    }
};

int main() {
	Solution solution;
	string haystack = "hello";
	string needle = "ll";
	
	cout << solution.strStr(haystack, needle);
	
	return 0;
} 

// Accepted!
