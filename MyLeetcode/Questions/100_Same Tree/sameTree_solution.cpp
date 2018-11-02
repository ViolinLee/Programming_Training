/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (random()%2){
            return isSameTree1(p, q);
        }
        return isSameTree2(p, q);
    }
    
    bool isSameTree1(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;  
        if(!p || !q) return false;  // 上一个return使下面的if有了else if的效果! 
        return (p->val == q->val) &&  
                isSameTree(p->left, q->left) &&   //isSameTree放在return里面;注意两个参数不是p->left,p->right 
                isSameTree(p->right, q->right);
    }
    
    bool isSameTree2(TreeNode *p, TreeNode *q) { //用queue实现的前序遍历 
        
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (q1.size()>0 && q2.size()>0 ){
            TreeNode* p1 = q1.front();
            q1.pop();
            TreeNode* p2 = q2.front();
            q2.pop();
            if (!p1 && !p2) continue;
            if (!p1 || !p2)  return false;

            if ( p1->val != p2->val) {
                return false;
            }

            q1.push(p1->left);
            q2.push(p2->left);

            q1.push(p1->right);
            q2.push(p2->right);

        }
        return true;
    }
    
    bool isSameTree3(TreeNode* p, TreeNode* q) { //用stack实现的root->right->left遍历顺序 
        stack<TreeNode*> s1, s2;
        if (p) s1.push(p);
        if (q) s2.push(q);
        while (!s1.empty() && !s2.empty()) {
            TreeNode *t1 = s1.top(); s1.pop();
            TreeNode *t2 = s2.top(); s2.pop();
            if (t1->val != t2->val) return false;
            if (t1->left) s1.push(t1->left);
            if (t2->left) s2.push(t2->left);
            if (s1.size() != s2.size()) return false;
            if (t1->right) s1.push(t1->right);
            if (t2->right) s2.push(t2->right);
            if (s1.size() != s2.size()) return false;
        }
        return s1.size() == s2.size();
    }
};
