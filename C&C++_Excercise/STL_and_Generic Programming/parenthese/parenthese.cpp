#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
	string test;
	int length;
	stack<char> temp;
	int flag = 0;
	
    cout << "请输入仅包含'('、 ')'、 '['、 ']'、 '{'、 '}'六种字符的字符串: " << endl; 
    cin >> test;
    length = test.size();
    cout << "输入的字符串为: " << test << "    长度为: "<<length << endl;
    
    if (length%2 != 0){
    	cout << "字符串无效" << endl;     // 若字符串长度为奇数，则无效 
	}
    else{
    	for (int i=0; i< length/2; ++i){
    		temp.push((char)test[i]);
		}
		for (int j=length/2; j<length; ++j){
			if ((char)test[j]==')'&&temp.top()=='('||(char)test[j]==']'&&temp.top()=='['||(char)test[j]=='}'&&temp.top()=='{'){  // 这里不做强制转换也通过 
				flag = 1;                                                                                                        // 证明string的对象里面放的是char 
				temp.pop();
			}
			else {
				flag =0;
				break;
			}
		}
		if (flag==0){cout << "字符串无效" << endl;}
		else { cout << "字符串有效" << endl;} 
	}
	
	return 0; 
}

