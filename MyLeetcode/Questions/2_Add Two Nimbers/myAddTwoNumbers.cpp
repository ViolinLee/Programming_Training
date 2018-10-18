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

