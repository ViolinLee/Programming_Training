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
	bool isValid(string str){
		stack<char> S; // 
		int len = str.length();
		//cout << len << endl;
		

		for (auto c : str) {
			if (S.size()>0) {
				if (S.top() == '[' || S.top() == '(' || S.top() == '{') {
				    if (S.top() == '[' && c == ']') {S.pop();}
			        else if (S.top() == '(' && c == ')') {S.pop();}
			        else if (S.top() == '{' && c == '}') {S.pop();}
			        else { S.push(c); cout << c << endl; }
			    }
			    
			}
			
			else {
				S.push(c);
				cout << c << endl;
			}
			
		}


		return S.empty();
	}
};

int main(){
	Solution solution;
	string A = "{{[]()}}";
	
	cout << solution.isValid(A) << endl;
	
	return 0;
}

//�����������ҵķ�����������ջ����ʲôԪ�����֣��ж�==Ҳ����ֱ�ӣ��ο���ת��Ϊ�����±�==�����ο��𰸵ķ����������Դ������Ԫ����ʲôԪ�����֡� 
//�����ö��е��������������������Եľ�pop��ֻ�ܱ�֤ͬ�����͵����ųɶԴ��ڣ����ܱ�֤˳�����Ҫ��
//ע�⣺C++�� stack Ϊ��ջʱ�����ʹ�� .top() �� DEV �лᷢ���������� 
