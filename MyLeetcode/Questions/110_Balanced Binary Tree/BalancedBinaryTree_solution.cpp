class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (checkDepth(root) == -1) return false;
		else return true;
	}
	
	int checkDepth(TreeNode *root) {
		if (root == nullptr) return 0; // 终止条件 
		
		int left = checkDepth(root->left);
		int right = checkDepth(root->right);
		
		if (left == -1 || right == -1 || abs(left - right) > 1) return -1; // 剪枝
		
		return max(left, right) + 1; // 三方合并 
	}
};

//相比调用 getDepth的解法（从根部到底部依次判断），优势在于一旦发现子树不平衡，则不计算具体深度，而是直接返回-1

