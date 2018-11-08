#include<iostream> 
#include<stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
		
		int cursum = root->val;
		TreeNode* cur = root;
		stack s;
        s.push(cur);
        
        while(!s.empty) {
        	while(cur!=nullptr){
        		if (cur->left != nullptr){
        			s.push(cur->left);
        			cursum += cur->right->val;
        			cur = cur->left;
				}
				else if (cur->right != nullptr){
					s.push(cur->right);
					cursum += cur->right->val;
					cur = cur->right;
				}
				
			}
        	cur
		}
    }
};

// 写不出...思路不清晰 
