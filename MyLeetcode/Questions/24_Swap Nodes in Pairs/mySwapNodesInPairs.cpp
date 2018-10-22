#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* newhead;
        
        if (cur!=nullptr && cur->next!=nullptr) { // 注：当cur==nullptr时，不会再判断cur->next!=nullptr。因此不必当心操作nullptr 
        	newhead = cur->next;
		} else {
			return cur;
		}
		
		ListNode dummy(-1);
        ListNode* pretemp = &dummy; // pretemp节点不能初始化为nullptr，否则不允许引用它的next 
		ListNode* nexttemp;
		
		while(cur!=nullptr&&cur->next!=nullptr) { // 注：当cur==nullptr时，不会再判断cur->next!=nullptr。因此不必当心操作nullptr
			nexttemp = cur->next->next;
			    
			pretemp->next = cur->next;
			pretemp->next->next = cur;
			cur->next = nexttemp;
			
			pretemp = cur;
			cur = nexttemp;
		} 		
		return newhead;
    }
};

int main() {
	Solution solution;
	
	// construct list
	int a[4]={1,2,3,4}; 
	vector<int> v(a,a+4);
	
	ListNode* dummy = new ListNode(-1);
	ListNode* cur = dummy;
	for (int i=0; i<v.size(); i++) {
		cur->next = new ListNode(v[i]);
		cur = cur->next;
		cout << cur->val;
	}
	cout << endl;
	
	ListNode* res = solution.swapPairs(dummy->next);
	
	while(res!=nullptr) {
		cout << res->val;
		res = res->next;
	}
	
	return 0;
}

/*思路：
1.分类讨论（奇偶）：if cur.next以及cur均不为空，则进入交换操作 
2.怎么换？ 
   1）考虑 1->2->3->4->5->6中的 3 4：2->1->3->4->5->6
   2）从左向右一对一对遍历 
3.准备变量：cur记录pair的头； pretemp记录前一对的尾巴（初始为nullptr）；nexttemp记录后一对的头（初始为cur.next.next）； 
*/ 
