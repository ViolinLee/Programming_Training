#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
		if (root->left) root->left->next = root->right;
		//if (root->next) root->right->next = root->next->left; // �������root->next==NULL,��root->next->left���Ϸ� 
		if (root->right) root->right->next = root->next? root->next->left : NULL;
		
		connect(root->left);
		connect(root->right);   
    }
};

void printTree(TreeLinkNode *root){ // ע���˴���printTreeҲʹ�õݹ�ʵ�֣���ӡ˳��root, root->left, root->right 
    if (root == NULL){
        return;
    }
    printf("[%d], left[%d], right[%d], next[%d]\n", 
            root->val, 
            root->left ? root->left->val : -1, 
            root->right ? root->right->val : -1, 
            root->next?root->next->val : -1 );    

    printTree(root->left);
    printTree(root->right);
 
}

int main()
{
    Solution solution;
    
	const int cnt = 7; 
    TreeLinkNode a[cnt];
    for(int i=0; i<cnt; i++){
        a[i].val = i+1;
    } 
    
    for(int i=0, pos=0;  pos < cnt-1; i++ ){
        a[i].left = &a[++pos];
        a[i].right = &a[++pos];
    }
    
    printTree(&a[0]);
    cout << "******************************************" << endl;
    
    solution.connect(&a[0]); 

    printTree(&a[0]);

    return 0;
}

// �����õݹ�ʵ�֣���˲��ǳ����ռ临�Ӷ� 
