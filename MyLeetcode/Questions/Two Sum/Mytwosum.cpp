#include<vector> 
#include<iostream>
#include <iterator>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> id;
		for(int i=0; i<nums.size(); i++) {
        	for(int j=i+1; j<nums.size(); j++) {
        		if(nums[i] + nums[j] == target)  {
				    id.push_back(i); 
					id.push_back(j);
				}
			}
		}
		return id;
    }
};

int main(){
	int Nums[] = {2, 11, 7, 15};
	vector<int> nums = vector<int>(begin(Nums), end(Nums)); // ʹ�������ʼ��vector�ķ�����Ҫʹ�õ�����iterator 
	int target = 9;
	Solution solution;
	
	vector<int> result = solution.twoSum(nums, target);
    for(int i=0; i<result.size(); i++) {
    	cout << result[i] << " ";
	}
		
	return 0;
}

//ע���𰸽���������������ɡ���һ������ 
//    find()�����ҵ�����index�����򷵻�containter��end() 
