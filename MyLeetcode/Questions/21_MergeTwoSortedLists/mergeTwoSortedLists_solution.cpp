class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for (; l1 != nullptr && l2 != nullptr; p = p->next) {
            if (l1->val > l2->val) { p->next = l2; l2 = l2->next; }
            else { p->next = l1; l1 = l1->next; }
        }
        
        p->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
};

/*
比较 
ListNode *dummy = new ListNode(-1); 
ListNode *cur = dummy;
dummy->next;

ListNode dummy(-1);
ListNode *cur = &dummy;
dummy.next;

dummy可以是ListNode本身，也可以是ListNode指针 
cur则必须是ListNode指针 
*/

