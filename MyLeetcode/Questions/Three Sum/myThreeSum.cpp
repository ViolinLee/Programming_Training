// ˼·������for���ڲ���set

#include <iostream>
#include <vector>
#include <set>

using namespace std;
Class Solution {
public:
	vector<vector<int>> threeSum(&nums<int>) { // �����ӿڣ������±���ҿ��ܲ�ֹһ�� 
	    vector<vector<int>> res;
		int n = nums.size();
	    set<int> s(nums);
	    
	    for (int i=0; i<n; i++) {
	    	for (int j=0; j<n; j++) { // ע�ⲻ�����ظ�Ԫ�� 
	    		if (nums[i] == nums[j]) continue;
	    		else {
	    			iter = s.find(-(nums[i]+nums[j]));
	    			if(iter) {
	    				vector<int> temp = {i, j, iter}
	    				res.push_back(temp);
					}
				}
			}
		}
	} 
	
}


/* ����ѭ�����˴���set�ķ�������ô�����ظ��⣨����+Ԫ���أ���ɾ��Ԫ�أ��ı�ֵ��
1.�����ظ�Ԫ��-->����������Ȼ��ÿ�αȽ����ڵ������� 
2.ɾ���ظ����-->�����ݽṹ map () 
*/ 
 
