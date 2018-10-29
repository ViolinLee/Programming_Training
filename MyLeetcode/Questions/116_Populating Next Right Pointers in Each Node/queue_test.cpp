#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {
	queue<int> a;
	a.push(1);
	a.pop();	
	cout << a.front() << endl; // q中没有元素时，q.front()返回? 1)在这之前a有元素； 2)a未初始化
	
    queue<int*> b;
	int c = 2;
	int* d = &c;
	b.push(d);
	b.pop();
	cout << b.front() << endl; // 即使queue里面没有元素，b.front()也不会返回NULL?   注意！！！front()返回oldest element！！！ 
	b.push(NULL);
	cout << b.front() << endl; // 但是如果queue里面的元素是NULL，b.front()返回NULL! 
	
	queue<string> q;
    q.push("Hello World!");
    q.push("China");
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
	
	
	
	return 0;
}
