#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) { // ע�����������߼��� 
    	if (root==nullptr) return true;
    	
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
        	return false;
		} 
        
		return isBalanced(root->left) && isBalanced(root->right); 
    }
};

int main() {
	Solution solution;
	
	TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
	
	cout << solution.isBalanced(root) << endl;
	
	return 0;
}

// ����˼·����Ҫ���Ի�ȡ���ĸ߶ȵĺ�����Ϊ���� 
// Ѱ�����Ч�Ľⷨ 
