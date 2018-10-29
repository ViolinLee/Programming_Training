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

// Recursion, more than constant space
class Solution_recursion {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right) root->right->next = root->next? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
    }
};

// Non-recursion, more than constant space
class Solution_queue {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur) {
                cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
            	cout << q.front();
                if (q.front()==NULL || q.front()==NULL) return; // q.size()==0 和 q.front()==NULL 是等价的吗？ 在leetcode上少任何一个都能通过 
                // 由于 q.front()返回oldest element.因此当queue被pop至空时，queue.front()还是会返回NULL。所以这里两个条件留一个即可 
				q.push(NULL);
            }
        }
    }
};

void printTree(TreeLinkNode *root){ // 注：此处的printTree也使用递归实现；打印顺序root, root->left, root->right 
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
{   /* TEST1
    Solution_queue solution;
    
	const int cnt = 7; 
    TreeLinkNode a[cnt];      // 使用数组方法同时创建多个 TreeLinkNode 
    for(int i=0; i<cnt; i++){
        a[i].val = i+1;
    } 
    
    for(int i=0, pos=0;  pos < cnt-1; i++ ){
        a[i].left = &a[++pos];
        a[i].right = &a[++pos];
    }
    
    solution.connect(&a[0]); 

    printTree(&a[0]);
    */
    
    // Test
    TreeLinkNode b;
    b.val = -1;
    Solution_queue s;
    s.connect(&b);
    printTree(&b);
    
    

    return 0;
}
