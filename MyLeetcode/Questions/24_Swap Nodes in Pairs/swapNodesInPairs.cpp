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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
                next;
                prev = cur, cur = cur->next, next = cur ? cur->next: nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};


int main() {
	Solution solution;
	
	// construct list
	int a[4]={1,2,3}; 
	vector<int> v(a,a+3);
	
	ListNode* dummy = new ListNode(-1);
	ListNode* cur = dummy;
	for (int i=0; i<v.size(); i++) {
		cur->next = new ListNode(v[i]);
		cur = cur->next;
		cout << cur->val;
	}
	cout << endl;
	
	ListNode* res = solution.swapPairs(dummy->next);
	
	while(res!=nullptr) {
		cout << res->val;
		res = res->next;
	}
	
	return 0;
}

/*ע��
1) ListNode* prev = &dummy; prev = cur; // ǰһ������prevָ��dummy; ��һ�������ı�prev��ֵ��ָ��ĵ�ַ��,��Ӱ��dummy�� 
2) ListNode* prev = &dummy; prev->next = next; // ���dummy���Ӱ��
3) ListNode* dummyptr; ListNode* prev = dummyptr; prev->next = next; // ���dummy���Ӱ��
���ۣ���ǳ���������ĳ�Ա���в�����Ӱ��Դ��������ǳ����������������ٸ�ֵ����Ӱ��Դ���� 
*/ 
