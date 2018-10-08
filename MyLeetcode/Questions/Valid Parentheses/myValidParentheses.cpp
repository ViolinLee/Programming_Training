/*
注意：
    1.题意两条原则: 
	(1) Open brackets must be closed by the same type of brackets --> 同类型引号左右括号数量一致 
	(2) Open brackets must be closed in the correct order --> 如果一对括号内存在另一括号，则必须有与该括号配对的括号存在 --> 必是({[()]})结构 ，{[(])} 是无效的。 
*/

#include<stack>
#include<string>
#include<iostream>

using namespace std;
class Solution{
public:
	bool isValid(char* A){
		stack<char> S; //
		string str = string(A);
		int len = str.length();
		
		for (int i=0; i<len; i++) {
			if (str[i] == S.top()) {
				S.pop();
			}
			else S.push(str[i]);
		}
		
		return S.empty();
	}
};

int main(){
	Solution solution;
	char A[] = "{{()[]}}";
	
	cout << solution.isValid(A);
	cout << 1;
	
	return 0;
}
