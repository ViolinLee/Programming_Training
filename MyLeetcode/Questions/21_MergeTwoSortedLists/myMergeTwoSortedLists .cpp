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

/* ˼·����ϵmerge sorted array
1.array�ǴӺ���ǰ��list�Ǵ�ǰ����
2.Ϊʲôarray�Ӻ���ǰ����Ϊarrayʵ���� merge into����������֮һ�������޸�
3.listʵ����new ListNode(-1)�������������� 
