#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_1 {
    
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};


class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1);  // ͷ�ڵ� 
		int carry = 0;
		ListNode *prev = &dummy;  
		 
		for (ListNode *h1 = l1, *h2 = l2; // ע���﷨�淶���˴������Ǳ��������ͳ�ʼ���������壩 
		    h1!=nullptr || h2!=nullptr;
		    h1 = (h1==nullptr)? nullptr : h1->next, // �˴�������"���Ų�����" 
			h2 = (h2==nullptr)? nullptr : h2->next,
			prev = prev->next) {
			const int val1 = (h1!=nullptr)? h1->val: 0;  
			const int val2 = (h2!=nullptr)? h2->val: 0;
 
			const int num = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			prev->next = new ListNode(num);  // β�巨	
		} 
		if (carry > 0) prev->next = new ListNode(carry); 
		
		return dummy.next;
	}
};

ListNode *addValAndCreateNewNode(ListNode *cur,int val){
    cur->val=val;
    cur->next=new ListNode(0);
    return cur->next;
}

int main() {
    Solution solution;
    int A[] = {2,4,7,9};
    int B[] = {5,6,4};
    ListNode *head = NULL;
    ListNode *head1 = (ListNode*)malloc(sizeof(ListNode)); // malloc�����ֶ������ֽ��������ڷ��غ�ǿ��ת��Ϊʵ�����͵�ָ�� 
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head1->next = NULL;
    head2->next = NULL;
    ListNode *node;
    ListNode *pre = head1;
    for(int i = 0;i < 4;i++){ // ��ν� �ַ���/�ַ�����/string ת��Ϊ Linked list����û�ж���chain����£� 
        node = (ListNode*)malloc(sizeof(ListNode)); // ��Ҫmalloc����ʹ��new������107�� 
        node->val = A[i];
        node->next = NULL;
        pre->next = node;
        pre = node;
    }
    pre = head2; // �ı�pre��ֵ�����ı�pre��ָ��ĵ�ַ�� 
    for(int i = 0;i < 3;i++){
        //node = (ListNode*)malloc(sizeof(ListNode));
        //node->val = B[i];
        //node->next = NULL;
        node = new ListNode(B[i]);
        pre->next = node;
        pre = node; // �� pre = pre->next; 
    }
    head = solution.addTwoNumbers(head1->next,head2->next);
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}

