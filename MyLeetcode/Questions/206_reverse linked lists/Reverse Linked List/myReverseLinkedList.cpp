#include<>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
		ListNode* pre = nullptr;
        ListNode* next;
        
        while(cur!=nullptr) {
        	next = cur->next;
        	cur->next = pre;
        	
        	pre = cur;
        	cur = next;
		}
        
        return pre;
        
    }
};
