#include<unordered_map>
#include<vector> 
#include<iostream>

using namespace std; 
class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < num.size(); i++) {
            mapping[num[i]] = i; // 一次性把所有num的元素都放进mapping中，而solution是逐渐放元素（最终不一定都放进过；放的是互补的数） 
        }
        for (int i = 0; i < num.size(); i++) {
            const int gap = target - num[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {  
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
            }
        }
        return result;
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
