#include<iostream>

using namespace std;
std::string dec2bin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return dec2bin(number / 2) + "0";
    else
        return dec2bin(number / 2) + "1";
}

//Ô­ÎÄ£ºhttps://blog.csdn.net/nixawk/article/details/48165023 

int main() {
	int i = 3;
	cout << i << ":";
	cout << dec2bin(i) << endl;
	
	cout << (i >> 1) << ":";
	cout << dec2bin(i >> 1) << endl;
	
	cout << ((i >> 1) ^ i) << ":";
	cout << dec2bin((i >> 1) ^ i) << endl;
	
	return 0;
}
