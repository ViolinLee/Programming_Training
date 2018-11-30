struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = dummy;
		ListNode *pre, *front, *last; // cur pre front last ? 
		for (int i = 1; i <= m - 1; ++i) cur = cur->next; // cur -> m-1位置 
		/*
		1->2->3->4->5   进入for循环前：pre(1) cur(1) front(-1) last(2) 
		1->3->4->5  2   一次for循环后：pre(1) cur(2) front(2)  last(2) 注：此时cur(2)->next是ListNode(-1) 
		1->4->5  3->2   二次for循环后：pre(1) cur(3) front(3)  last(2)
		1->5  4->3->2   三次for循环后：pre(1) cur(4) front(4)  last(2)
		1->4->3->2->5
		*/
		pre = cur; // pre是子链表的前一个节点 (1) 
		last = cur->next; // last是子链表翻转完成后的最后一个节点 (2) 
		for (int i = m; i <= n; ++i) {
			cur = pre->next;
			pre->next = cur->next;
			cur->next = front;
			front = cur; 
		}
		cur = pre->next; 
		pre->next = front; 
		last->next = cur;
		return dummy->next;
	}
}; 

// 太繁杂了...... 
