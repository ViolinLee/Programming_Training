// 64λ Dev-C++����
 
#ifndef __FRUIT__
#define __FRUIT__

#include <iostream>
using namespace std;

class Fruit{
protected:
    int no;
    double weight;
    char key;
public:
	Fruit() {}
	void print() {
	    cout << "sizeof(f.no)=" << sizeof(no) << endl;  
        cout << "sizeof(f.weight)=" << sizeof(weight) << endl;  
        cout << "sizeof(f.key)=" <<sizeof(key) << endl;
        cout <<"************************************"<< endl; 
        cout << "address of (f):" << this << endl; 
        cout << "address of (f.no):" << &no << endl;
        cout << "address of (f.weight):" << &weight << endl;
        // C++��׼����I/O������������<<���أ������ַ���ָ��ʱ�Ὣ�䵱���ַ��������������ָ����ָ���ַ���.��ǿ��char *ת����void *
        cout << "address of (f.key):" << hex << static_cast<void*>(&key) << endl; 
	}
	virtual void process(){    }
};

class Apple: public Fruit{
protected:
	int size;
	char type;
public:
	void print(){
		cout << "sizeof(a.no)=" << sizeof(no) << endl;  
        cout << "sizeof(a.weight)=" << sizeof(weight) << endl;  
        cout << "sizeof(a.key)=" << sizeof(key) << endl;  
        cout << "sizeof(a.size)=" << sizeof(size) << endl;  
        cout << "sizeof(a.type)=" << sizeof(type) << endl;
		cout <<"************************************"<< endl; 
		cout << "address of (a):" << this << endl; 
		cout << "address of (a.no):" << &no << endl;
		cout << "address of (a.weight):" << &weight << endl;
		cout << "address of (a.key):" << hex << static_cast<void*>(&key) << endl;
		cout << "address of (a.size):" << &size << endl;
		cout << "address of (a.type):" << static_cast<void*>(&type) << endl;  
	}
	void save(){    }
	virtual void process(){    }
};

#endif
