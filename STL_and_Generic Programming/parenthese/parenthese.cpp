#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
	string test;
	int length;
	stack<char> temp;
	int flag = 0;
	
    cout << "�����������'('�� ')'�� '['�� ']'�� '{'�� '}'�����ַ����ַ���: " << endl; 
    cin >> test;
    length = test.size();
    cout << "������ַ���Ϊ: " << test << "    ����Ϊ: "<<length << endl;
    
    if (length%2 != 0){
    	cout << "�ַ�����Ч" << endl;     // ���ַ�������Ϊ����������Ч 
	}
    else{
    	for (int i=0; i< length/2; ++i){
    		temp.push((char)test[i]);
		}
		for (int j=length/2; j<length; ++j){
			if ((char)test[j]==')'&&temp.top()=='('||(char)test[j]==']'&&temp.top()=='['||(char)test[j]=='}'&&temp.top()=='{'){  // ���ﲻ��ǿ��ת��Ҳͨ�� 
				flag = 1;                                                                                                        // ֤��string�Ķ�������ŵ���char 
				temp.pop();
			}
			else {
				flag =0;
				break;
			}
		}
		if (flag==0){cout << "�ַ�����Ч" << endl;}
		else { cout << "�ַ�����Ч" << endl;} 
	}
	
	return 0; 
}

