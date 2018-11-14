#include <iostream>
#include <vector> 

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode* dummy = new ListNode(-1);
        dummy->next =  head;
		
		ListNode* temp = dummy; // 想到用来记录最后一个调到target前的值 
        ListNode* cur = head;
        ListNode* pre = dummy; // cur被调前后，cur未调前时的上一个节点指向cur未调前时的下一个节点 
        
		while(cur != nullptr) {
			if (cur->val >= x) {
				pre->next = cur;
				pre = cur;
				
				cur = cur->next;
			} else { // 这种情况还要分开讨论，甚是细节！ 
				if (cur == temp->next) { 
					temp = cur;
					pre = cur;
					cur = cur->next;
				} else{
					ListNode* CUR = cur->next;
					ListNode* NEXT = temp->next; 
				
					temp->next = cur;
					cur->next = NEXT;
				
					temp = cur;
					cur = CUR; // pre 不变 
					pre->next = cur;
				}	
			}
		}
		return dummy->next;
    }
};

int main() {
	Solution solution;
	ListNode* dummy = new ListNode(-1);
	vector<int> v = {1,4,3,2,5,2};
	int target = 3;
	
	ListNode* p = dummy;
	for (auto n : v) {
		p->next = new ListNode(n);
		p = p->next;
	}
	
	ListNode* head = solution.partition(dummy->next, target);
	while(head != nullptr) {
		cout << head->val;
		head = head->next;
	}
	
	return 0;
}

// OJ上测试效率是 100% ，思路和解法1接近，解法1的step1相当于跳过了if (cur == temp->next)。 
