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

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1); // 头节点
		int carry = 0; // 记录进位 
		ListNode *prev = &dummy; // 这种做法不会开辟新的内存空间；只是创建一个新指针，值用dummy的地址赋予；后续更改不会影响dummy 
		// ListNode prev = dummy; // 直接赋值结构体可以吗? 结构体直接赋值会开辟新的ListNode空间，再完成元素拷贝（深）。
		// 这样二者的地址就没联系了... 
		
		ListNode* h1 = l1; // =右边是指针（而指针的值就是地址）；所以h1现在的值就是l1的值，即现在h1和h2指向的地址相同； 
		ListNode* h2 = l2; // 深浅拷贝是相对于两个指针所指向的对象而言的；单独定义指针并初始化没有这种问题 
		 
		while(h1!=nullptr || h2!=nullptr) {
			int val1 = (h1!=nullptr)? h1->val: 0;  
			int val2 = (h2!=nullptr)? h2->val: 0;
			
			/*if (carry==1) {
				int num = (val1 + val2 +1);
			}
			else num = val1 + val2; 
		    prev.val = num%10; */
		    // 废话一大堆，用下面的两句替代 
			int num = (val1 + val2 + carry) % 10;
			carry = (val1 + val2 + carry) / 10;
			prev->next = new ListNode(num); // 尾插法 
			
			h1 = (h1==nullptr)? nullptr : h1->next; // 不能简单地：h1 = h1->next;
			h2 = (h2==nullptr)? nullptr : h2->next;
			prev = prev->next;
		} 
		if (carry > 0) prev->next = new ListNode(carry); // 处理最大位数上可能的进位 
		
		return dummy.next;
	}
};

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        int flag = 0;
        do {
            if ((l1->val + l2->val)<10) {
                if (flag = 0) {
                    result->val = l1->val + l2->val;
                    result = result->next;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                else {
                    result->val = l1->val + l2->val + 1;
                    result = result->next;
                    l1 = l1->next;
                    l2 = l2->next;
                    flag = 0;
                }
            } else {
                result->val = (l1->val + l2->val)%10;
                flag = 1;
            }
            
        } while(l1->next);
        return result;
    }
};
*/

/*
class Solution {
    
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
};*/

/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l0 = nullptr, * l3 = nullptr;
        int a = 0;

        while( l1 or l2 or a ) {
            if(l1){
                a+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                a+=l2->val;
                l2 = l2->next;
            }
            
            if(l3) {
                l3->next = new ListNode(a%10);
                l3 = l3->next;
            }
            else {
                l3 = l0 = new ListNode(a%10);
            }
            a /= 10;
        }
        
        return l0;
    }
};
*/

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
    	cout << line <<endl;
        ListNode* l1 = stringToListNode(line);
        string s1 = listNodeToString(l1);
        vector<int> v1  = stringToIntegerVector(s1);
        for(int i=0;i<v1.size();i++) {
    	    cout << v1[i] << endl;
	    }
        
        getline(cin, line);
        cout << line <<endl;
        ListNode* l2 = stringToListNode(line);
        string s2 = listNodeToString(l2);
        vector<int> v2  = stringToIntegerVector(s2);
        for(int i=0;i<v2.size();i++) {
    	    cout << v2[i] << endl;
	    }
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    
    /*
    string a = "[2345]";
    ListNode* l = stringToListNode(a);
    string a_ = listNodeToString(l);
    vector<int> v  = stringToIntegerVector(a);
    vector<int> v_ = stringToIntegerVector(a_);
    for(int i=0;i<v.size();i++) {
    	cout << v[i] << endl;
    	cout << v_[i] << endl;
    	cout << endl;
	}*/
	
    
    return 0;
}

// 注：从leetcode上copy的debug代码在本地可能产生奇怪结果...... 
