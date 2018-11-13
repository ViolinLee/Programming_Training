#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        // ����ָ���ҵ��м�ڵ㣨��������������±깫ʽ�� 
		ListNode *fast = head, *slow = head;
	    while (fast->next != NULL && fast->next->next != NULL) {
	    	fast = fast->next->next;
	    	slow = slow->next;
		} 
		// �Ͽ�(д�ò�������)
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		
		ListNode *l1 = sortList(head); // ǰ�������
		ListNode *l2 = sortList(slow); // �������� 
		return mergeTwoLists(l1, l2);
    }
    
    // Merge Two Sorted Lists
	ListNode *mergeTwoLists_(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1);
		for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
			int val1 = l1 == nullptr ? INT_MAX : l1->val;
			int val2 = l2 == nullptr ? INT_MAX : l2->val;
			if (val1 <= val2) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	} 
	
	//  �Ľ�merge 
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1);
		for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
			if (l1 == nullptr) {
				p->next = l2;
				break;
			}
			if (l2 == nullptr) {
				p->next = l1;
				break;
			}
			else {
				int val1 = l1->val;
			    int val2 = l2->val;
			    if (val1 <= val2) {
				    p->next = l1;
				    l1 = l1->next;
			    } else {
				    p->next = l2;
				    l2 = l2->next;
			    }
			} 	
		}
		return dummy.next;
	}
};

int main() {
	Solution solution;
	vector<int> v = {4,2,1,3};
	
	ListNode* dummy = new ListNode(-1);
	ListNode* p = dummy;
	
	for (auto e : v) {
		p->next = new ListNode(e);
		p = p->next;
	}
	
	ListNode* l = dummy;
	solution.sortList(l);
	
	while(l != nullptr) {
		cout << l->val << " ";
		l = l->next;
	}
	
	
	return 0;
}


/*
1.���������㷨����������ѡ�����򡢶����򡢿�������ð�����򡢹鲢����Ͱ���� �� 
2.ʱ�临�Ӷ� O(nlgn) ���������򡢹鲢���򡢶����� 
3.�������ʺ��ù鲢����˫�����ʺ��ÿ������� 
4.��ָ���ҵ��м�ڵ�
5.�Ͽ�����ܼ򵥣��Ͽ�����ڵ�ָ��nullptr����
6.merge sortedlist�ĳ�����ʵ�����ã���Ϊ��һ��Ԫ������󣬻�����һ��ʣ�µ�Ԫ�ؽ���һ�����ӡ����ʱ��ʹp->nextָ��ʣ�������ͷ������,���Ľ�merge��
  ������OJ���к���ʱ���������� 
*/ 
