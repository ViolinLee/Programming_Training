/*���Ϊ����С���⣺
1.ʹ�ÿ���ָ����������е�
2.��ת�ڶ��������� 
3.���ڶ���������Ԫ�ؼ�������һ�������� 
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
		while (fast->next && fast->next->next) { // �����е� 
			slow = slow->next;
			fast = fast->next->next;
		}
		
		ListNode* mid = slow->next;
		slow->next = NULL; // �Ͽ����� 
		ListNode* last = mid;
		ListNode* pre = NULL;
		
		while (last) { // ��ת�б� 
			ListNode* next = last->next; 
			last->next = pre;
			
			pre = last;
			last = next;
		} 
		
		while (head && pre) { // ������� 
			ListNode* next = head->next;
			head->next = pre;
			pre = pre->next;
			head->next->next = next;
			head = next;
		}
	}
};
