class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
};

/*
我的思路：递归
1.遍历wordDict，每取一个word，遍历一次s，检查存在多少个WORD1，记录位置；若不存在，返回false； 
2.遍历每个WORD1，每次将当前WORD1从完整的s中删除；
3.接着取下一个word，遍历修改后的s,检查存在多少个WORD2，记录位置；若不存在，返回false；
4.遍历每个WORD2，每次将当前WORD2从完整的s中删除；
...
如果遍历到WORDn，且存在，则返回True 

注：这种方法明显没有理解题意，题意是分成k段后（k>1），形成的k+1段形成的k+1个word都能从worddict中找到 
*/
