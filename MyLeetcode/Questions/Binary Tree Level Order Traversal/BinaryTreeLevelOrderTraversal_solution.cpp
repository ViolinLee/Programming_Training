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

vector<TreeNode*> TreeToArray_level_order(TreeNode* root);
vector<vector<int> > zigzagLevelOrder1(TreeNode *root);
vector<vector<int> > zigzagLevelOrder2(TreeNode *root);


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    if (rand()%2){
        return zigzagLevelOrder1(root);
    }
    return zigzagLevelOrder2(root);
}

vector<vector<int> > zigzagLevelOrder1(TreeNode *root) {
    vector<vector<int> > result;
    vector<TreeNode*> tree = TreeToArray_level_order(root);

    int curLevelCnt = 1;
    int nextLevelCnt = 1;
    int level=0;

    for (int i=0; i<tree.size(); i+=curLevelCnt ){
        int cnt=0;
        level++;
        vector<int> v;
        if (level%2==0){
            for(int j=i+nextLevelCnt-1; j>=i; j--){
                if (tree[j]){
                    cnt += 2;
                    v.push_back(tree[j]->val);
                }
            }
        }else{
            for(int j=i; j<i+nextLevelCnt; j++){
                if (tree[j]){
                    cnt += 2;
                    v.push_back(tree[j]->val);
                }
            }
        }
        curLevelCnt = nextLevelCnt;
        nextLevelCnt = cnt;
        if (v.size()>0){
            result.push_back(v);
        }
    }
    return result;
}

vector<TreeNode*> TreeToArray_level_order(TreeNode* root){
    vector <TreeNode*> result;

    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0) {
        TreeNode* n = q.front();
        q.pop();
        result.push_back(n);
        if (n==NULL){
            //cout << "# ";
            continue;
        }
        //cout << n->val << " ";
        q.push(n->left);
        q.push(n->right);
    }
    //cout << endl;
    return result;
}

vector<vector<int> > zigzagLevelOrder2(TreeNode *root) {
    vector<vector<int> > vv;
    if(root == NULL) return vv;

    int level = 0;
    TreeNode *last = root;
    queue<TreeNode*> q;

    q.push(root);
    vv.push_back(vector<int>());
    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        vv[level].insert(level%2 ? vv[level].begin() : vv[level].end(), p->val);
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);

        if(p == last) {
            level++;
            last = q.back();
            vv.push_back(vector<int>());
        }
    }
    vv.pop_back();

    return vv;
}

void printTree_level_order(TreeNode *root) // 答案中的printTree_level_order()函数就是最经典的遍历方法 
{
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()>0){
        TreeNode* n = q.front();
        q.pop();
        if (n==NULL){
            cout << "# ";
            continue;
        }
        cout << n->val << " ";
        q.push(n->left);
        q.push(n->right);
    }
    cout << endl;
}

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

int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << " ]" << endl;;
    }
}


int main(int argc, char** argv)
{
    TreeNode *p;
    vector< vector<int> > vv;

    int a[] = {3,9,20,0,0,15,7};
    p = createTree(a, sizeof(a)/sizeof(int));
    printTree_level_order(p);
    vv = zigzagLevelOrder(p);
    printMatrix(vv);
    cout << endl;


    return 0;
}
