#include<stack>
#include<vector>
#include<iostream>

using namespace std;

struct treeNode{
	int val;
	treeNode* left;
	treeNode* right;
	treeNode(int theVal): val(theVal), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(treeNode* BT){
	treeNode* T;
	T = BT;
	vector<int> result;
	stack<treeNode*> s;
	
	while(T || !s.empty()) {  // 外层循环：条件1 -> 首次进入循环；条件2 -> 回溯 + 遍历右子树
		while(T) {            // 内层循环：一直向左并将沿途结点压入堆栈 
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		result.push_back(T->val);
	    T = T->right;
	}
	
	return result;
	
}

treeNode* createTree(int a[], int n) // createTree 返回的类型是 TreeNode*  
{
    if (n<=0) return NULL;

    treeNode **tree = new treeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new treeNode(a[i]);
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

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9};
	treeNode* T = createTree(a, 9);
	vector<int> v = inorderTraversal(T);
	
	for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
	
	return 0;
}
 
