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
		    while(p->left != nullptr) { /* ������һ��root�Ŀ�ʼ������������ */ 
        	    s.push(p);
			    p = p->left;
		    }
			q = nullptr; /* ÿ�α����µ�root������Ҫ���ó�Ϊnullptr*/
			
			while(!s.empty()){ /* ÿ���״ν��붼��������Ҷ�ڵ�ʱ */ 
				p = s.top();
				s.pop();
				/* �Һ��Ӳ����ڻ��ѱ����ʣ���ʱroot��left��right�������ʹ���������֮�����Է���root�� 
				   �����������ͬһ���ж������� */ 
				if(p->right == q) {
					result.push_back(p-val);
					q = p; /* ����շ��ʹ��Ľڵ� */ 
				} else {
					/* ��ǰ�ڵ㲻�ܷ��ʣ���ڶ��ν�ջ */
					s.push(p);
					/* �ȴ��������� */
					p = p->right;
					break; 
				}
			}
		    } 
		} while(!s.empty());
		return result; 
    }
};

/*ע��1.�����ѭ��ʹ��ͬһ������������ 
      2.�𰸽�����һ�������������� ������1 && ����2��ʵ��
	  3.��if�����������������෴��ϵ������Ҳ���˶��ν�ջ*/ 
