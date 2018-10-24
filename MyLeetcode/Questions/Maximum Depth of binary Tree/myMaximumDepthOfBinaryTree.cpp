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
    	/*���汻ע�͵�����Ǵ���ӦΪ root == NULL��
		  ����maxDepth(root->left)�е�leftΪNULLʱ��������NULL->left������runtime error
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


