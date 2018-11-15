#include <set>

using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (!head) return NULL;
    	
        RandomListNode* dummy = new ListNode(-1);
        set<RandomListNode*> randNodeSet;
        
        while(head != null) {
        	if (randNodeSet.find(head) != randNodeSet.end()) { // 若head已在Set中，则dummy指向head？不行，head是原链表节点 
        		randNodeSet.push(head);
        		dummy->next = new RandomListNode(head->label);
			} else dummy->next = new RandomListNode(head->label);
        	
        	
        	if (randNodeSet.find(head->random) != randNodeSet.end()) {
        		randNodeSet.push(head->random);
        		dummy->random = head->random;
			} else {
				dummy->random = new RandomListNode(head->random->label)
			}
        	
        	head = head->next;
        	dummy = dummy->next;
		}
		return dummy->next;
    }
};

//错误 
