// Iterative
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		
		while (cur->next) {
			ListNode* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = dummy->next; // 这里的dummy->next相当关键 
			dummy->next = tmp;
		}
		return dummy->next;
	}
}; 

// Recursive
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head; // base case 
		
		ListNode* p = head;
		head = reverseList(p->next);
		p->next->next = p; // p->next此时是上面reverseList(p->next)的最后一个元素 
		p->next = NULL;
		
		return head;
	}
};

// 递归正向理解值观；但是要写出顺序或者是深入理解的话，需要从base case开始反向推回来 
