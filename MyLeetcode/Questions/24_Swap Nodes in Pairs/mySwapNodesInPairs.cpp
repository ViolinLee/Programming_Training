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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* newhead;
        
        if (cur!=nullptr && cur->next!=nullptr) { // ע����cur==nullptrʱ���������ж�cur->next!=nullptr����˲��ص��Ĳ���nullptr 
        	newhead = cur->next;
		} else {
			return cur;
		}
		
		ListNode dummy(-1);
        ListNode* pretemp = &dummy; // pretemp�ڵ㲻�ܳ�ʼ��Ϊnullptr������������������next 
		ListNode* nexttemp;
		
		while(cur!=nullptr&&cur->next!=nullptr) { // ע����cur==nullptrʱ���������ж�cur->next!=nullptr����˲��ص��Ĳ���nullptr
			nexttemp = cur->next->next;
			    
			pretemp->next = cur->next;
			pretemp->next->next = cur;
			cur->next = nexttemp;
			
			pretemp = cur;
			cur = nexttemp;
		} 		
		return newhead;
    }
};

int main() {
	Solution solution;
	
	// construct list
	int a[4]={1,2,3,4}; 
	vector<int> v(a,a+4);
	
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

/*˼·��
1.�������ۣ���ż����if cur.next�Լ�cur����Ϊ�գ�����뽻������ 
2.��ô���� 
   1������ 1->2->3->4->5->6�е� 3 4��2->1->3->4->5->6
   2����������һ��һ�Ա��� 
3.׼��������cur��¼pair��ͷ�� pretemp��¼ǰһ�Ե�β�ͣ���ʼΪnullptr����nexttemp��¼��һ�Ե�ͷ����ʼΪcur.next.next���� 
*/ 
