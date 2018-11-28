/*拆分为三个小问题：
1.使用快慢指针查找链表中点
2.翻转第二个子链表 
3.将第二个子链表元素间隔插入第一个链表中 
*/

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (!head || !head->next || !head->next->next) return;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next) { // 查找中点 
			slow = slow->next;
			fast = fast->next->next;
		}
		
		ListNode* mid = slow->next;
		slow->next = NULL; // 断开链表 
		ListNode* last = mid;
		ListNode* pre = NULL;
		
		while (last) { // 翻转列表！ 
			ListNode* next = last->next; 
			last->next = pre;
			
			pre = last;
			last = next;
		} 
		
		while (head && pre) { // 间隔插入 
			ListNode* next = head->next;
			head->next = pre;
			pre = pre->next;
			head->next->next = next;
			head = next;
		}
	}
};
