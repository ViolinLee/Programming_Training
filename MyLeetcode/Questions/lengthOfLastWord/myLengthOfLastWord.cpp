#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {// ע������ϸ�ģ����ܽ����β�пո�����!  "Hello World   "�� World Ҳ�����һ���� 
public:
	int lengthOfLastWord(const char *s) {
		int size = strlen(s);
		if (size == 0) return 0;
		
		int res;
		int count = 0;
		for (int i = 0; i < size; i++) {
		    if (s[i] == ' ') count = 0;
			else count++; 
		}
		
		return count;
	} 
}; 


int main() {
	Solution solution;
    char* s = "Hello world\nHi"; // ע�⣬����Ὣ���з���Ϊһ�ַ� 
    cout << s << endl; 
    
    cout << solution.lengthOfLastWord(s);

	return 0;
}

/* ע 
1.�����ϣ�sizeof(int) = 4; sizeof(char) = 1;
2.  char str[5] = "1234";
    cout << sizeof(str) / sizeof(char); // ���Ϊ5��sizeof()��ʵ��ռ���ڴ�ռ�Ĵ�С 
	cout << strlen(str); // �����4��ʵ���ַ�����С
	
	char *str = "1234";
	cout << sizeof(str) / sizeof(char); // �����8�������str��һ��ָ���ַ���"1234"��ָ�룬�������ַ�������(�ַ�����) 
*/
