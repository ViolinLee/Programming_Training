#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	return distance(A, unique(A, A + n)); //或者 unique(A, A + n) - A; 数组在编译器看来就是地址！！！ 
	} 
};

