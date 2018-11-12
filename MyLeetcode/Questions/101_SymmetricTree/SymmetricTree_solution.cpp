
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// �ݹ�汾 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;  // ��ֹ���� 
        if (!left || !right) return false; // ��ֹ���� 
        return left->val == right->val     // �����ϲ� 
		       && isSymmetric(left->left, right->right) 
			   && isSymmetric(left->right, right->left);
    }
    
};

// �����汾֮����queue(˼·ֱ�ӣ����ױ��)
// ���Կ���ͬ����α���������������������֤�Գ�λ�õ�ֵ��� 
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
                q1.push(node1->left); // q1��q2����left��right��˳��ͬ 
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }
        return true;
    }
};

/***************************************************************************************************/ 
// ����˼·�ļ򻯰棨��Ȼ�ǲ�α����� 
// �����汾֮һ��queue��java�汾�� 
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
        
        q.add(t1.left); // ע����� 
        q.add(t2.right);
        
        q.add(t1.right);
        q.add(t2.left);
    }
    return true;
}

// �ǲ�α�����ʽ������������������������֤�Գ�λ�õ�ֵ��� 
// �����汾֮һ��stack
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

