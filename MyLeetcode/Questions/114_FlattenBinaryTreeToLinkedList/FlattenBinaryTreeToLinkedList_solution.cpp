// 方法一、先序遍历：preorder-traversal(recursion) 递归解法是从底向上 
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return; 
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        
		// 以下为遍历某父节点的左、右节点后进行的操作，以成为元素顺序同先序的链表 
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL; // !!! 
        while (root->right) root = root->right; // 走到节点 
        root->right = tmp;
    }
};

// 方法二、非递归 
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

// 方法二、非递归——用栈实现(iterative)
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

/*
问题：解法二虽然是非递归，但和非递归前序遍历算法本身确实没什么关系。那可不可以用非递归前序遍历(栈辅助)实现？ 
答：应该是不行的。不管是在push_back(n->right)还是在push_back(n->left)后修改，都会影响后面stack的推入。 
*/ 
