// preorder-traversal(recursion) 递归一定要从base case逐渐递归 
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return; 
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL; // !!! 
        while (root->right) root = root->right; // 走到节点 
        root->right = tmp;
    }
};

// preorder-traversal(iterative)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right ) s.push(t->right);
        }
    }
};


// 其他方法：非迭代(Non-recursion)
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};


