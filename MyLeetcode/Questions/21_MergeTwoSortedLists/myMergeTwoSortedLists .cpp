#include <iostream> 

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    }
};

int main() {
	
	
	return 0;
}

/* 思路：联系merge sorted array
1.array是从后往前；list是从前往后
2.为什么array从后往前？因为array实质是 merge into，即在其中之一数组上修改
3.list实质是new ListNode(-1)，即建立新链表 
