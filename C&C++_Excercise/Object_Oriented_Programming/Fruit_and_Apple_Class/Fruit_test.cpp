#include "Fruit.h"
#include <iostream>
using namespace std; 

int main() {
    Fruit f;
    Apple a;
    cout << "Fruit����f��size��: " << sizeof(f) << endl;
    f.print();
    
    cout <<endl;
    
    cout << "Apple����a��size��: " << sizeof(a) << endl;
    a.print();

    return 0;
}
