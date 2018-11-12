class Solution {
public:
    string countAndSay(int n) {
    	
    	
    	int n_pre = (int) countAndSay(n - 1);
        return countAndSay(n_pre);
        
    }
};
