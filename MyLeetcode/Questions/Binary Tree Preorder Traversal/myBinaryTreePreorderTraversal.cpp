#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> PreorderTraversal(TreeNode* T) {
		TreeNode* p;
		stack<int> s;
		vector<int> result;
		
		p = T;
		if (p != nullptr) s.push(p);
		
		while (!s.empty()) {
			p = s.top();
			result.push_back(p->val); // ��s.pop()����˳��Ӱ���� 
			s.pop();
			
			if (p->right != nullptr) s.push(p->right);
			if (p->left != nullptr) s.push(p->left);
		}	
		return result;
	}
};

// ����1.stack<*>ģ���������int����TreeNode* 
