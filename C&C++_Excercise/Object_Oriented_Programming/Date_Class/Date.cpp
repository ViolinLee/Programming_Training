#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Date.h"

using namespace std;

int main()
{
    srand((int) time(0));
    
	Date* test = CreatePoints();
	cout<<"����������ڣ�"<<endl;
	for( int i=0; i<10; ++i) test[i].print();
	
	Sort( test);
	cout<<"������������"<<endl;
	for(int i =0; i<10; ++i) test[i].print();
	
	return 0; 
}
