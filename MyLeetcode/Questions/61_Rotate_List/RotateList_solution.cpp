struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
    	if (!head) return NULL;
    	int n = 0;
    	ListNode *cur = head;
    	while(cur) { // ����һ������õ�������n 
    		++n;
    		cur = cur->next;
		}
		k %= n; // ��������nȡ��
		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; ++i) { // ��ָ������k�� 
			if (fast) fast = fast->next;
		} 
		if (!fast) return head;
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head; // �ɻ� 
		fast = slow->next; // ��ȡhead 
		slow->next = NULL; // �ϻ� 
		return fast;
	}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head) return NULL;
		int n = 1;
		ListNode *cur = head;
		while (cur->next) { // ������ȡ������ 
			++n;
			cur = cur->next;
		}
		cur->next = head; // �ɻ�
		int m = n - (k % n); // m��û�б���ת��Ԫ�صĸ���
		for (int i = 0; i < m; ++i) {
			cur = cur->next;
		} 
		ListNode *newhead = cur->next;
		cur->next = NULL;
		return newhead;
	}
}; 



