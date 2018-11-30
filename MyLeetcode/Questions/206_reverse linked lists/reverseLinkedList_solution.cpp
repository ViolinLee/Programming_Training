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
			tmp->next = dummy->next; // �����dummy->next�൱�ؼ� 
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
		p->next->next = p; // p->next��ʱ������reverseList(p->next)�����һ��Ԫ�� 
		p->next = NULL;
		
		return head;
	}
};

// �ݹ��������ֵ�ۣ�����Ҫд��˳��������������Ļ�����Ҫ��base case��ʼ�����ƻ��� 
