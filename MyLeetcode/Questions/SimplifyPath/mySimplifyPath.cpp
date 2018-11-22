#include <vector>
#include <iostream> 
#include <string.h>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<char> res;
        int size = path.size();
        
        for (int i = 0; i < size; i++) {
        	if(path[i] == '/' && !res.empty() && (res.back() == '/' || res.back() == '.'|| i == size-1) ) {
        		continue;
			}
        	else if(path[i] == '.') {
        		if (i < size-1 && path[i+1] == '.' && !res.empty()) {
        			if (res.back() == '/' && res.size() > 1) {
        				res.pop_back();
        				res.pop_back();
        				i++;
        				if (res.back() == '/') {
        					res.pop_back();
						}
					}
					else if(res.size() > 1){
						res.pop_back();
						i++;
                    }
                    else {
						i++;
                    }
				} 
			}
	
        	else res.push_back(path[i]);
		}

		return string(res.begin(), res.end());
    }
};

int main() {
	Solution solution;
	string path = "/a//b////c/d//././/..";
	string PATH = solution.simplifyPath(path);
	
	cout << PATH;
	
	return 0;
}

//Í¨²»¹ý "/..."
