#include<iostream>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	/*下面被注释的这句是错误，应为 root == NULL。
		  否则当maxDepth(root->left)中的left为NULL时，这里变成NULL->left，属于runtime error
        if (root->left==nullptr && root->right==nullptr) return 0; */
        
        if (root == nullptr) return 0;
 
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
	int res;
	Solution solution;
	
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    res = solution.maxDepth(root);
	cout << res;
	
	return 0;
}


