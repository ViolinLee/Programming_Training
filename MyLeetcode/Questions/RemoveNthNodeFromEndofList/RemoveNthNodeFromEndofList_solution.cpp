class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL; // ����ϸ��1 
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; ++i) cur = cur->next;
        if (!cur) return head->next; // ����ϸ��2 
        
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
