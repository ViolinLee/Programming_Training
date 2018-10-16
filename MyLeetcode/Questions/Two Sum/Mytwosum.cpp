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
	vector<int> nums = vector<int>(begin(Nums), end(Nums)); // 使用数组初始化vector的方法需要使用迭代器iterator 
	int target = 9;
	Solution solution;
	
	vector<int> result = solution.twoSum(nums, target);
    for(int i=0; i<result.size(); i++) {
    	cout << result[i] << " ";
	}
		
	return 0;
}

//注：答案将“找两个数”变成“找一个数” 
//    find()函数找到返回index；否则返回containter的end() 
