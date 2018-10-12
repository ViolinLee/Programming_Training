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
			result.push_back(p->val); // 和s.pop()交换顺序不影响结果 
			s.pop();
			
			if (p->right != nullptr) s.push(p->right);
			if (p->left != nullptr) s.push(p->left);
		}	
		return result;
	}
};

// 错误1.stack<*>模板参数不是int而是TreeNode* 
