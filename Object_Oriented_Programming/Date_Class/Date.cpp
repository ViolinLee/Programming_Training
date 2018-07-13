#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Date.h"

using namespace std;

int main()
{
    srand((int) time(0));
    
	Date* test = CreatePoints();
	cout<<"产生随机日期："<<endl;
	for( int i=0; i<10; ++i) test[i].print();
	
	Sort( test);
	cout<<"日期排序结果："<<endl;
	for(int i =0; i<10; ++i) test[i].print();
	
	return 0; 
}
