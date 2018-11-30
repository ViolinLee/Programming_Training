Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // Approach 1��Divide and Conquer  
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) { // ���η������Լ��������ܻ����ż����... 
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {  
            int k = (n + 1) / 2; // ̫�����ˣ������˷���������ż 
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};

#include<queue>
struct cmp {
	bool operator () (ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};

class Solution { // Min Heap (very nice!) 
public:
	ListNode* mergeKLists(vector<ListNode*> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q; // priority_queue<Type, Container, Functional>
		for (int i = 0; i < lists.size(); ++i) { // ���Ȱ�k��������׽ڵ㶼������С�� 
			if (lists[i]) q.push(lists[i]);
		}
		
		ListNode* head = NULL, *pre = NULL, *tmp = NULL;
		while (!q.empty()) {
			tmp = q.top(); // ÿ��ȡ��ֵ��С�ڵ� 
			q.pop;
			if (!pre) head = tmp; // ��ʼ��� 
			else pre->next = tmp; // �ǳ�ʼ��� 
			pre = tmp;
			if (tmp->next) q.push(tmp->next); // ��ȡ���ڵ��next�ڵ��Ƴ���С�� 
		}
		return head;
	}
};



