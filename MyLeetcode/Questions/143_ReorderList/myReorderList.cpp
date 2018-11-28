#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // ����һ���ȡ������
		int len = 0;
		ListNode* cur = head;
		while(cur) {
			len++;
			cur = cur->next;
		} 
		if (len<3) return;
		
		int num = 1; 
		cur = head;
		while(num <= len/2) {
			cur = cur->next;
			num++;
		}
        ListNode* mid = cur->next;
        cur->next = NULL;
        
        stack<ListNode*> s;
        while(mid) {
        	s.push(mid);
        	mid = mid->next;
		}
		
		cur = head;
		
		while(!s.empty()) {
			ListNode* tmp = cur->next;
			cur->next = s.top();
			s.pop();
			cur->next->next = tmp;
			cur = tmp;
		}
		
    }
};

int main() {
	Solution solution;
	ListNode* p = new ListNode(-1);
	vector<int> v = {1,2,3,4,5};
	ListNode* start = p;
	for (auto n : v) {
		start->next = new ListNode(n);
		start = start->next;
	}
	
	solution.reorderList(p->next);
	while(p->next) {
		cout << p->next->val << " ";
		p = p->next;
	}
	
	return 0;
}

/*
˼·���԰봦�� --> ����ż���� --> ������ͨ��
��������stack����ؽ���˷�ת�������⣬��û��ʹ�ô𰸵ķ�ת���� 
beat 50.55% 
*/ 
