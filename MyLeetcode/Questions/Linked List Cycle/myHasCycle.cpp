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

/* 使用unordered_setd的方法 
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

// 使用快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* fast = head;
    	ListNode* slow = head;
    	int flag = 0;
    	
    	while(fast!=nullptr) { // 用这种方式实现的快慢指针，遍历的速度比较慢，因为快指针没次循环只走一步 
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
	
	/* 去掉这段代码进行有环链表的测试 
	// 增加一个节点，其next指向第二个节点 
	cur->next = new ListNode(5);
	cur = cur->next;
	cout << cur->val;
	cur->next = dummy->next->next; // 制造环 
	*/
	
	cout << endl << solution.hasCycle(dummy->next);
	
	return 0;
}

/* 
1. unordered_map的使用：
  包含头文件：#include<tr1/unordered_map>
  [查找元素是否存在] mp.find(x)!=mp.end(); 
  [插入数据] map.insert(meke_pair(1,"Raoul")); (可以有四种方式实现)
  [遍历map] 
    unordered_map<key, T>::iterator it;
    (*it).first;  // the key value
    (*it).second; // the mapped value
    
    方式1： 
    for(unordered_map<key, T>::iterator iter=mp.begin();iter!=mp.end();iter++)
        cout << "key value is" << iter->first << "the mapped value is" << iter->second;
    
	方式2：
	for(auto& v:mp)
	    cout << "key value is" << v.first << "the mapped value is" << v.second;

2. 为了严谨性，最好在开头判断一下传入的是否为空链表/一个节点的链表	
*/	    
