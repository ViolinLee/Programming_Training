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

//程序正常，我的分类讨论是以栈顶是什么元素来分，判断==也过于直接（参考答案转化为数组下标==）。参考答案的分类讨论是以待加入的元素是什么元素来分。 
//错误：用队列的做法（遇到和最左边配对的就pop）只能保证同种类型的括号成对存在，不能保证顺序符合要求。
//注意：C++的 stack 为空栈时，如果使用 .top() 在 DEV 中会发生程序奔溃！ 
