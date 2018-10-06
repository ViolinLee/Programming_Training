#include "Fruit.h"
#include <iostream>
using namespace std; 

int main() {
    Fruit f;
    Apple a;
    cout << "Fruit对象f的size是: " << sizeof(f) << endl;
    f.print();
    
    cout <<endl;
    
    cout << "Apple对象a的size是: " << sizeof(a) << endl;
    a.print();

    return 0;
}
