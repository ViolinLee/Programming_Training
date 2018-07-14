#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
	Rectangle rec0;
	cout << rec0 << endl;
	
	Rectangle rec1(1,2,0,0);
	Rectangle rec2(3,4,2,2);
	
	Rectangle rec3(rec2);      // ¿½±´¹¹Ôì 
	cout << rec3 << endl;
	
	rec3 = rec1;               // ¿½±´¸³Öµ 
	cout << rec3 << endl;
	cout << rec2 << endl;
	cout << rec1 << endl;	
}
