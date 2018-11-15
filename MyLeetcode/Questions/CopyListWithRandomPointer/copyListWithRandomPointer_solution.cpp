// �ص����ڴ������ָ�� 

class Solution {
public:
	RandomListNode* copyRandomList(RandomListNode* head) {
		if (!head) return NULL;
		
		RandomListNode* res = new RandomListNode(head->label); // �±�ͷ�����ڷ��� 
		RandomListNode* node = res; // ���ڱ����±� 
		RandomListNode* cur = head->next;
		
		map<RandomListNode*, RandomListNode*> m; // ԭ�ڵ����½ڵ�Ĺ�ϣ�� 
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
// ע������������Ŀ��Ҫ�õ�dummy�ڵ㣻��Ȼ��dummy�ǿ��Եģ���ʱ��ͬhead���ڵĽڵ㶼��while���洦��


// �ڶ��ֽⷨʮ��������ñ���ԭʼ�����ӳ���ϵ�������½ڵ�ʱ�����½ڵ���뵽��Ӧ�ľɽڵ���� 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        RandomListNode *cur = head;
        while (cur) { // �½ڵ���뵽��Ӧ�ľɽڵ�� 
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node; // ���޸�ԭ���� 
            cur = node->next;
        }
        
        cur = head;
        while (cur) { // Ϊ�½ڵ��random��ֵ 
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        
        cur = head;
        RandomListNode *res = head->next; //res ��ָ���һ���½ڵ� 
        while (cur) { // �ָ�ԭ�ڵ� 
            RandomListNode *tmp = cur->next; // tmp��¼��ǰԭ�ڵ��Ӧ�ĵ�ǰ�½ڵ� 
            cur->next = tmp->next;
            if(tmp->next) tmp->next = tmp->next->next; // if(tmp->next)ָ��ǰ�½ڵ��ǲ�����β 
            cur = cur->next;
        }
        return res;
    }
};

// ˼·�����������ϸ�ڱȽ϶�
