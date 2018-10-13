#include<vector>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        const TreeNode *p, *q;
        stack<const TreeNode*> s;
        p = root;
        
        do { 
		    while(p->left != nullptr) { /* 遍历任一级root的开始，并往左下走 */ 
        	    s.push(p);
			    p = p->left;
		    }
			q = nullptr; /* 每次遍历新的root，就需要重置成为nullptr*/
			
			while(!s.empty()){ /* 每次首次进入都是在遇到叶节点时 */ 
				p = s.top();
				s.pop();
				/* 右孩子不存在或已被访问（这时root的left和right均杯访问过），访问之（可以访问root） 
				   这两种情况用同一条判断语句包含 */ 
				if(p->right == q) {
					result.push_back(p-val);
					q = p; /* 保存刚访问过的节点 */ 
				} else {
					/* 当前节点不能访问，需第二次进栈 */
					s.push(p);
					/* 先处理右子树 */
					p = p->right;
					break; 
				}
			}
		    } 
		} while(!s.empty());
		return result; 
    }
};

/*注：1.内外层循环使用同一个条件，怪吗？ 
      2.答案将这里一条语句两种情况用 “条件1 && 条件2”实现
	  3.答案if语句的条件和这里是相反关系，于是也少了二次进栈*/ 
