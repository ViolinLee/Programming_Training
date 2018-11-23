#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = beginWord.size();
        int n = endWord.size();
        if (m != n) return false;
        
        int path = 0;
        for (int i = 0; i < wordList.size(); i++) {
        		
        	if (transformable(wordList[i], beginWord)) {
        		beginWord = wordList[i];
        		path++;
			}
			
			if (beginWord == endWord) {
        		return path;
			}
		}
		
		return false;
    }
    
    bool transformable(string a, string b) {	
    	int diff_num = 0;
    	for (int i = 0; i < a.size(); i++) {
    		if (a[i] != b[i]) {
    			diff_num++;
			}
		}
		return diff_num == 1 ? 1 : 0;
	}
};

int main() {
	Solution solution;
	string beginWord = "hot";
    string endWord = "dog";
    vector<string> wordList = {"hot","dog","dot"};
	
	cout << solution.ladderLength(beginWord, endWord, wordList);
	return 0;
}

// 注意，这道题里面的transform顺序不一定是wordList里面的顺序！所以通不过上面的例子。题目有难度... 
