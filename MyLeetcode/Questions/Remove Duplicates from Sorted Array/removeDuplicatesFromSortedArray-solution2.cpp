#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	return distance(A, unique(A, A + n)); //���� unique(A, A + n) - A; �����ڱ������������ǵ�ַ������ 
	} 
};

