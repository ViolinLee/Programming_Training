#include<stdio.h>
#include<iostream>
#include<array>

using namespace std; 

class Solution {
public:
	array<int> removeDup(array input_array) {
		int length = input_array.size();
		int record_array[length] = {};
		int back = -1;
		int count = -1;
		
		for (auto it = input_array.begin(); it != input_array.end(), ++it){
		
		    int cur = input_array[it];
			if back == cur {
			    ;
			}
		    else {
		    	count++;
		    	record_array[count] = cur;
		    	back = cur;
			}
 	    }
	    array<int, count> output_array = { record_array }
	    
	    return output_array;
	}	
};


# ����ˣ��������ɾ����Ԫ�صĸ���������ֱ���޸�ԭ�������飬�����Ƿ��ظ����� 
