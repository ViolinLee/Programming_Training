#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	multiset<int> myset; 
	set<int> aux;
	string cmd;
	int n, num, temp;
	
	cin >> n;
	while(n--)
	{
		cin >> cmd >> num;
		switch(cmd[1])
		{
		    case 'd':
		    	myset.insert(num);
		    	aux.insert(num);
		    	temp = myset.count(num);
		    	cout << temp << endl;
		    	break;
		    case 'e':
	            temp = myset.count(num);
		    	myset.erase(num);
		    	cout << temp << endl;
		    	break;
		    case 's':
		    	if (aux.find(num) == aux.end()){
		    		cout << "0 0" << endl;
				}
				else{
					temp = myset.count(num);
					cout << "1 " << temp << endl;
				}	
		    	break;
		    	
		}
	}
	
	return 0;
}
