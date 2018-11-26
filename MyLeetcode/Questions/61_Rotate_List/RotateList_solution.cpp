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
    	while(cur) { // 遍历一遍链表得到链表长度n 
    		++n;
    		cur = cur->next;
		}
		k %= n; // 对链表长度n取余
		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; ++i) { // 快指针先走k步 
			if (fast) fast = fast->next;
		} 
		if (!fast) return head;
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head; // 成环 
		fast = slow->next; // 提取head 
		slow->next = NULL; // 断环 
		return fast;
	}
};

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head) return NULL;
		int n = 1;
		ListNode *cur = head;
		while (cur->next) { // 遍历获取链表长度 
			++n;
			cur = cur->next;
		}
		cur->next = head; // 成环
		int m = n - (k % n); // m是没有被旋转的元素的个数
		for (int i = 0; i < m; ++i) {
			cur = cur->next;
		} 
		ListNode *newhead = cur->next;
		cur->next = NULL;
		return newhead;
	}
}; 



