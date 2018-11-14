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
		
		ListNode* temp = dummy; // �뵽������¼���һ������targetǰ��ֵ 
        ListNode* cur = head;
        ListNode* pre = dummy; // cur����ǰ��curδ��ǰʱ����һ���ڵ�ָ��curδ��ǰʱ����һ���ڵ� 
        
		while(cur != nullptr) {
			if (cur->val >= x) {
				pre->next = cur;
				pre = cur;
				
				cur = cur->next;
			} else { // ���������Ҫ�ֿ����ۣ�����ϸ�ڣ� 
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
					cur = CUR; // pre ���� 
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

// OJ�ϲ���Ч���� 100% ��˼·�ͽⷨ1�ӽ����ⷨ1��step1�൱��������if (cur == temp->next)�� 
