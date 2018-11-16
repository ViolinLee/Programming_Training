class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
		
		for (int i = 0; i < 9; ++i) {
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++j) //检查行：此时i是行j是列 
			    if (!check(board[i][j], used))
				    return false;
			
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++) //检查列：此时j是行，i是列 
			    if (!check(board[j][i], used))
			        return false;
	    }
	    
	    for (int r = 0; r < 3; ++r)  // 检查9个子格子——四层for（两层遍历9个位置;两层遍历一个子格子） 
	        for (int c = 0; c < 3; ++c) {
	        	fill(used, used + 9, false);
	        	
	        	for (int i = r * 3; i < r * 3 + 3; ++i)
	        	    for (int j = c * 3; j < c *3 + 3; ++j)
	        	        if (!check(borad[i][j], used))
	        	            return false;
			}
		
		return true;
    }
    
    bool check(char ch, bool used[9]) {
    	if (ch == '.') return true;
    	
    	if (used[ch - '1']) return false;
    	
    	used[ch - '1'] = true; // 或合并为一句：return used[ch - '1'] = true;
    	return true;
	}
};

// 我的思路：先一行行、一列列；再分别检查9个子格子 
