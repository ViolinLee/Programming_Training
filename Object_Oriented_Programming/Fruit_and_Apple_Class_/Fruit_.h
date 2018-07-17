#ifndef __FRUIT__
#define __FRUIT__

#include <iostream>
using namespace std;

class Fruit{
    int no;
    double weight;
    char key;
public:
    Fruit() { cout<< "Create Fruit" << endl;}
    
    //父类的析构函数声明为虚函数，作用是用父类的指针删除一个派生类对象时，
	//派生类对象的析构函数会被调用, 这样才不会造成内存泄漏。 
    virtual ~Fruit() { cout<< "Delete Fruit" << endl;}
    
    void print() {   }
    virtual void process(){   }
};
   
class Apple: public Fruit{
    int size;
    char type;
public:
	Apple() { cout<< "Create Apple" << endl;}
    ~Apple() { cout<< "Delete Apple" << endl;}
    
    // 重载::operator new和 ::operator new[] 
    void* operator new(size_t size)
    {
        if (Apple* p = (Apple*)malloc(size))
        {
        cout << "Call Apple::operator new   Size = " << size << "   prt = "<< p << endl;
        return p;
        }
        else
            throw bad_alloc();
    }
    void* operator new[](size_t size)
    {
        if (Apple* p = (Apple*)malloc(size))
        {
		cout << "Call Apple::operator new[]   Size = " << size << "   prt = "<< p << endl;
        return p;
        }
        else throw bad_alloc();
    }
    
    // 重载::operator delete和 ::operator delete[] 
    void operator delete (void* p, size_t size)
    {
        cout << "Call Apple::operator delete    Size = " << size << "   prt = "<< p << endl;
        free(p);
    }
    void operator delete[] (void* p, size_t size)
    {
        cout << "Call Apple::operator delete[]    Size = " << size << "   prt = "<< p << endl;
        free(p);
    }
	void save() {   }
    virtual void process(){   }
};

#endif 
