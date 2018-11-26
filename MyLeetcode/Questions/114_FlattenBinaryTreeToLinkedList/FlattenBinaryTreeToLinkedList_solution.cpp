// ����һ�����������preorder-traversal(recursion) �ݹ�ⷨ�Ǵӵ����� 
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return; 
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        
		// ����Ϊ����ĳ���ڵ�����ҽڵ����еĲ������Գ�ΪԪ��˳��ͬ��������� 
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL; // !!! 
        while (root->right) root = root->right; // �ߵ��ڵ� 
        root->right = tmp;
    }
};

// ���������ǵݹ� 
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

// ���������ǵݹ顪����ջʵ��(iterative)
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
���⣺�ⷨ����Ȼ�Ƿǵݹ飬���ͷǵݹ�ǰ������㷨����ȷʵûʲô��ϵ���ǿɲ������÷ǵݹ�ǰ�����(ջ����)ʵ�֣� 
��Ӧ���ǲ��еġ���������push_back(n->right)������push_back(n->left)���޸ģ�����Ӱ�����stack�����롣 
*/ 
