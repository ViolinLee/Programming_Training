class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
		
		for (int i = 0; i < 9; ++i) {
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++j) //����У���ʱi����j���� 
			    if (!check(board[i][j], used))
				    return false;
			
			fill(used, used + 9, false);
			for (int j = 0; j < 9; ++) //����У���ʱj���У�i���� 
			    if (!check(board[j][i], used))
			        return false;
	    }
	    
	    for (int r = 0; r < 3; ++r)  // ���9���Ӹ��ӡ����Ĳ�for���������9��λ��;�������һ���Ӹ��ӣ� 
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
    	
    	used[ch - '1'] = true; // ��ϲ�Ϊһ�䣺return used[ch - '1'] = true;
    	return true;
	}
};

// �ҵ�˼·����һ���С�һ���У��ٷֱ���9���Ӹ��� 
