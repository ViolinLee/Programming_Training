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
        
        // 快慢指针找到中间节点（如果是数组则用下标公式） 
		ListNode *fast = head, *slow = head;
	    while (fast->next != NULL && fast->next->next != NULL) {
	    	fast = fast->next->next;
	    	slow = slow->next;
		} 
		// 断开(写得不够清晰)
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		
		ListNode *l1 = sortList(head); // 前半段排序
		ListNode *l2 = sortList(slow); // 后半段排序 
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
	
	//  改进merge 
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
1.常见排序算法：插入排序、选择排序、堆排序、快速排序、冒泡排序、归并排序、桶排序 等 
2.时间复杂度 O(nlgn) ：快速排序、归并排序、堆排序 
3.单链表适合用归并排序；双链表适合用快速排序 
4.慢指针找到中间节点
5.断开链表很简单，断开处左节点指向nullptr就行
6.merge sortedlist的程序其实并不好，因为在一方元素排完后，还对另一方剩下的元素进行一次连接。这个时候使p->next指向剩下链表的头就行了,见改进merge。
  但是在OJ运行好像时间慢。。。 
*/ 
