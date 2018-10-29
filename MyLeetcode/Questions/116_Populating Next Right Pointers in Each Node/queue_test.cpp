#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {
	queue<int> a;
	a.push(1);
	a.pop();	
	cout << a.front() << endl; // q��û��Ԫ��ʱ��q.front()����? 1)����֮ǰa��Ԫ�أ� 2)aδ��ʼ��
	
    queue<int*> b;
	int c = 2;
	int* d = &c;
	b.push(d);
	b.pop();
	cout << b.front() << endl; // ��ʹqueue����û��Ԫ�أ�b.front()Ҳ���᷵��NULL?   ע�⣡����front()����oldest element������ 
	b.push(NULL);
	cout << b.front() << endl; // �������queue�����Ԫ����NULL��b.front()����NULL! 
	
	queue<string> q;
    q.push("Hello World!");
    q.push("China");
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
	
	
	
	return 0;
}
