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
    
    //�����������������Ϊ�麯�����������ø����ָ��ɾ��һ�����������ʱ��
	//�������������������ᱻ����, �����Ų�������ڴ�й©�� 
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
    
    // ����::operator new�� ::operator new[] 
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
    
    // ����::operator delete�� ::operator delete[] 
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
