#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    }
};

int main() {
	
	
	return 0;
}

// 我的想法是层次遍历，然后在每一层调用另一个判断是否对称的函数 
