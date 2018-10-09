#include<stack>
#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    bool isValid (string const& s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        
		for (auto c : s) {
		    if (left.find(c) != string::npos) {
				stk.push (c);
			} else {
				if (stk.empty () || stk.top () != left[right.find (c)])
					return false;
			    else
			        stk.pop ();
            }
        }
        return stk.empty();
    }
};

int main(){
	Solution solution;
	string A = "{{()[]}}";
	
	cout << solution.isValid(A) << endl;
	
	char a = 'a';
	char b = 'a';
	cout << (a == b) << endl;  // ���⣺�ж��ַ���� 
	
	stack<char> stk;
	cout << stk.top() << endl;; //���⣺ ������ 
	
	return 0;
}
