
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归版本 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;  // 终止条件 
        if (!left || !right) return false; // 终止条件 
        return left->val == right->val     // 三方合并 
		       && isSymmetric(left->left, right->right) 
			   && isSymmetric(left->right, right->left);
    }
    
};

// 迭代版本之两个queue(思路直接；容易编程)
// 可以看作同步层次遍历左子树与右子树，保证对称位置的值相等 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();
            q1.pop();
            q2.pop();
            if((node1 && !node2) || (!node1 && node2)) return false;
            if (node1) {
                if (node1->val != node2->val) return false;
                q1.push(node1->left); // q1和q2加入left和right的顺序不同 
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }
        return true;
    }
};

/***************************************************************************************************/ 
// 上面思路的简化版（依然是层次遍历） 
// 迭代版本之一个queue（java版本） 
public boolean isSymmetric(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    q.add(root);
    
    while (!q.isEmpty()) {
        TreeNode t1 = q.poll();
        TreeNode t2 = q.poll();
        
        if (t1 == null && t2 == null) continue;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        
        q.add(t1.left); // 注意次序 
        q.add(t2.right);
        
        q.add(t1.right);
        q.add(t2.left);
    }
    return true;
}

// 非层次遍历方式来遍历左子树与右子树，保证对称位置的值相等 
// 迭代版本之一个stack
class Solution {
public:
    bool isSymmetric (TreeNode* root) {
        if (!root) return true;
        
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        
        while (!s.empty ()) {
            auto p = s.top (); s.pop();
            auto q = s.top (); s.pop();
            
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            
            s.push(p->left);
            s.push(q->right);
            
            s.push(p->right);
            s.push(q->left);
        }
        
        return true;
    }
};

