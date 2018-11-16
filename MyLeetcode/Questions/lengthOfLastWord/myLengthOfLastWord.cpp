#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
class Solution {// 注：不够细心，不能解决结尾有空格的情况!  "Hello World   "的 World 也是最后一个词 
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
    char* s = "Hello world\nHi"; // 注意，程序会将换行符视为一字符 
    cout << s << endl; 
    
    cout << solution.lengthOfLastWord(s);

	return 0;
}

/* 注 
1.本机上，sizeof(int) = 4; sizeof(char) = 1;
2.  char str[5] = "1234";
    cout << sizeof(str) / sizeof(char); // 结果为5，sizeof()是实际占用内存空间的大小 
	cout << strlen(str); // 结果是4，实际字符串大小
	
	char *str = "1234";
	cout << sizeof(str) / sizeof(char); // 结果是8，这里的str是一个指向字符串"1234"的指针，不再是字符数组名(字符串名) 
*/
