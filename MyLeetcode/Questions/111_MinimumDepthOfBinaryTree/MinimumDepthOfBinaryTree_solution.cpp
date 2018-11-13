struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // 我思路的递归版本：缺陷：在左右子树的深度相差很多的时候，深的那边仍要遍历完整才能确定深度 
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        
        if (root->left == NULL) return minDepth(root->right) + 1;
        else if (root->right == NULL) return minDepth(root->left) + 1;
        else return 1 + min(minDepth(root->left), minDepth(root->right));
    }  
};


class Solution { //  
public:
    int minDepth(const TreeNode *root) {
        return minDepth(root, false);
    }
private:
    static int minDepth(const TreeNode *root, bool hasbrother) {
    	// INT_MAXl:把决定权(靠min()决定)交给NULL的brother，因为他们的root不是叶子节点
		// 0:NULL没有brother，证明root是叶子节点 
        if (!root) return hasbrother ? INT_MAX : 0; 
        
        return 1 + min(minDepth(root->left, root->right != NULL),
            minDepth(root->right, root->left != NULL)); 
    }
};
