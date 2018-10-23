#include<iostream> 
#include<vector>
#include<tr1/unordered_map>

using namespace std::tr1;
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* ʹ��unordered_setd�ķ��� 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* l = head;
        unordered_map<int, int> mp;
        int i = 0;
        
        while(l!=nullptr) {
        	int val = l->val;
        	if (mp.find(val)!=mp.end()) {
        		return true;
			} else {
				mp.insert({val, 1});
			}
        	
        	l = l->next;
		}
		return false;
    }
};
*/

// ʹ�ÿ���ָ��
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* fast = head;
    	ListNode* slow = head;
    	int flag = 0;
    	
    	while(fast!=nullptr) { // �����ַ�ʽʵ�ֵĿ���ָ�룬�������ٶȱȽ�������Ϊ��ָ��û��ѭ��ֻ��һ�� 
    		if (flag==1) {
                fast = fast->next;
    			slow = slow->next;
				flag = 0;
			} else {
				fast = fast->next;
				flag = 1;
			}
			
    		if (fast == slow) return true;
		
		}
		return false;
	}	
};



int main() {
	Solution solution;
	
	int a[4]={1,2,3,4}; 
	vector<int> v(a,a+4);
	ListNode* dummy = new ListNode(-1);
	ListNode* cur = dummy;
	for (int i=0; i<v.size(); i++) {
		cur->next = new ListNode(v[i]);
		cur = cur->next;
		cout << cur->val;
	}
	
	/* ȥ����δ�������л�����Ĳ��� 
	// ����һ���ڵ㣬��nextָ��ڶ����ڵ� 
	cur->next = new ListNode(5);
	cur = cur->next;
	cout << cur->val;
	cur->next = dummy->next->next; // ���컷 
	*/
	
	cout << endl << solution.hasCycle(dummy->next);
	
	return 0;
}

/* 
1. unordered_map��ʹ�ã�
  ����ͷ�ļ���#include<tr1/unordered_map>
  [����Ԫ���Ƿ����] mp.find(x)!=mp.end(); 
  [��������] map.insert(meke_pair(1,"Raoul")); (���������ַ�ʽʵ��)
  [����map] 
    unordered_map<key, T>::iterator it;
    (*it).first;  // the key value
    (*it).second; // the mapped value
    
    ��ʽ1�� 
    for(unordered_map<key, T>::iterator iter=mp.begin();iter!=mp.end();iter++)
        cout << "key value is" << iter->first << "the mapped value is" << iter->second;
    
	��ʽ2��
	for(auto& v:mp)
	    cout << "key value is" << v.first << "the mapped value is" << v.second;

2. Ϊ���Ͻ��ԣ�����ڿ�ͷ�ж�һ�´�����Ƿ�Ϊ������/һ���ڵ������	
*/	    
