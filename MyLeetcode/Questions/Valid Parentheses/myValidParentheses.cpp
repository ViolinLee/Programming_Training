/*
ע�⣺
    1.��������ԭ��: 
	(1) Open brackets must be closed by the same type of brackets --> ͬ��������������������һ�� 
	(2) Open brackets must be closed in the correct order --> ���һ�������ڴ�����һ���ţ�����������������Ե����Ŵ��� --> ����({[()]})�ṹ ��{[(])} ����Ч�ġ� 
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
