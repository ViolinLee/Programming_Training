#include <iostream>
#include <stack>

using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // 使用递归的前序遍历实现 
        TreeNode* pc = p;
        TreeNode* qc = q;
        
        if(!p && !q) return true; //注意：两颗空的Tree也是相等的！ 
        
        if (pc!=nullptr && qc!=nullptr)  {
        	if (pc->val == qc->val) continue;
        	else return false;
		}
        isSameTree(pc->left); // 错误的递归用法 
        isSameTree(pc->right);
        
        return true;
    }
};

class Solution2 {
public:
	boll isSameTree(TreeNode* p, TreeNode* q) { // 使用栈的前序遍历 
		stack<TreeNode*> s1, s2;
		if (p) s1.push(p);
		if (q) s2.push(q);
		
		while(!s1.empty() && !s2.empty()) { // 原本我是想while(!s1.empty()) { if (!s2.empty()) ...} 
			TreeNode* temp1 = s1.pop(); // 错误：TreeNode *t1 = s1.top(); s1.pop(); 效果不一样 stack.pop()返回void!!! 
			TreeNode* temp2 = s2.pop();
			
			if (temp1->val != temp2->val) return false;
				
			if (temp1->right!=nullptr) s1.push(temp1->right);
			if (temp2->right!=nullptr) s2.push(temp2->right);
		    if (s1.size() != s2.size()) return false;
		    
		    if (temp1->left!=nullptr) s1.push(temp1->left);
			if (temp2->left!=nullptr) s2.push(temp2->left);
		    if (s1.size() != s2.size()) return false;
		}
		
		return s1.size() == s2.size();
	}
};







