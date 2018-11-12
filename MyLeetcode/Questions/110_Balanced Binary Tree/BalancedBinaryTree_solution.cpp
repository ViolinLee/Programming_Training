class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (checkDepth(root) == -1) return false;
		else return true;
	}
	
	int checkDepth(TreeNode *root) {
		if (root == nullptr) return 0; // ��ֹ���� 
		
		int left = checkDepth(root->left);
		int right = checkDepth(root->right);
		
		if (left == -1 || right == -1 || abs(left - right) > 1) return -1; // ��֦
		
		return max(left, right) + 1; // �����ϲ� 
	}
};

//��ȵ��� getDepth�Ľⷨ���Ӹ������ײ������жϣ�����������һ������������ƽ�⣬�򲻼��������ȣ�����ֱ�ӷ���-1

