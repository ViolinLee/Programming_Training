struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // ��˼·�ĵݹ�汾��ȱ�ݣ�������������������ܶ��ʱ������Ǳ���Ҫ������������ȷ����� 
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
    	// INT_MAXl:�Ѿ���Ȩ(��min()����)����NULL��brother����Ϊ���ǵ�root����Ҷ�ӽڵ�
		// 0:NULLû��brother��֤��root��Ҷ�ӽڵ� 
        if (!root) return hasbrother ? INT_MAX : 0; 
        
        return 1 + min(minDepth(root->left, root->right != NULL),
            minDepth(root->right, root->left != NULL)); 
    }
};
