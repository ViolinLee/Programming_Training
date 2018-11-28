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
        // 遍历一遍获取链表长度
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
思路：对半处理 --> 奇数偶数？ --> 在这里通用
我这里用stack巧妙地解决了翻转插入问题，而没有使用答案的翻转链表 
beat 50.55% 
*/ 
