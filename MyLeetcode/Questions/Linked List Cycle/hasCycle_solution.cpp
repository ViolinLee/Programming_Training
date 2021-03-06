#include<iostream> 

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		// 设置两个指针，一个快一个慢
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) { // 注：防止对空指针操作 
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		} 
		return false;
	}
};
