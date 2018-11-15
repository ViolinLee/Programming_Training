// 重点在于处理随机指针 

class Solution {
public:
	RandomListNode* copyRandomList(RandomListNode* head) {
		if (!head) return NULL;
		
		RandomListNode* res = new RandomListNode(head->label); // 新表头，用于返回 
		RandomListNode* node = res; // 用于遍历新表 
		RandomListNode* cur = head->next;
		
		map<RandomListNode*, RandomListNode*> m; // 原节点与新节点的哈希表 
		m[head] = res;
		
		while(cur) {
			RandomListNode* tmp = new RandomListNode(cur->label);
			node->next = tmp;
			m[cur] = tmp;
			node = node->next;
			cur = cur->next;
		}
		
		node = res;
		cur = head;
		while (node) {
			node->random =m[cur->random];
			node = node->next;
			cur = cur->next;
		}
		return res;
	}
};
// 注：不是所有题目都要用到dummy节点；当然用dummy是可以的，这时连同head在内的节点都在while里面处理


// 第二种解法十分巧妙，不用保存原始链表的映射关系，构建新节点时，把新节点插入到相应的旧节点后面 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        RandomListNode *cur = head;
        while (cur) { // 新节点插入到相应的旧节点后 
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node; // 会修改原链表 
            cur = node->next;
        }
        
        cur = head;
        while (cur) { // 为新节点的random赋值 
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        cur = head;
        RandomListNode *res = head->next; //res 是指向第一个新节点 
        while (cur) { // 恢复原节点 
            RandomListNode *tmp = cur->next; // tmp记录当前原节点对应的当前新节点 
            cur->next = tmp->next;
            if(tmp->next) tmp->next = tmp->next->next; // if(tmp->next)指当前新节点是不是链尾 
            cur = cur->next;
        }
        return res;
    }
};

// 思路很清晰，编程细节比较多
