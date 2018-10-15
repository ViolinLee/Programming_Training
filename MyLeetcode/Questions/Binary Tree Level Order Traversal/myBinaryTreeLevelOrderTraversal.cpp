#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> levelOrderTraversal(TreeNode* T) {
		vector<int> result;
		queue<TreeNode*> q;
		q.push(T);
		TreeNode* cur;
		
		while(!q.empty()) {
			cur = q.front();
			q.pop();
			
			if(cur==NULL) { //��Ϊq��pushʱδ�ж��Ƿ�Ϊnullptr�����ܳ�����ڵ�Ϊnullptr�ҽڵ���������� 
				continue;
			}
			result.push_back(cur->val);
			q.push(cur->left);
			q.push(cur->right);
		}
	    
	    return result;
	}
};

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

int main(int argc, char** argv)
{
    TreeNode *p;
    Solution solution;
    vector<int> v;

    int a[] = {3,9,20,0,0,15,7};
    p = createTree(a, sizeof(a)/sizeof(int));
    v = solution.levelOrderTraversal(p);
    
    for(int i=0;i<v.size(); i++) {
    	cout << v[i] << " ";
	}
    cout << endl;

    return 0;
}

//ע����Ŀ��Ҫ�󷵻ظ�ʽ��matrix,�����Ƕ�ά��ʽ��������Ҫ����ı�������־���ڷ��ʵĲ㣬�Լ�������һ��Ҫ���ʵĲ㡣 
