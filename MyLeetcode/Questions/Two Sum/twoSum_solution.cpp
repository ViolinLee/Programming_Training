#include<unordered_map>
#include<vector> 
#include<iostream>

using namespace std;
class Solution {
public:
    /*
     *   The easy solution is O(n^2) run-time complexity.
     *   ```
     *       foreach(item1 in array) {
     *           foreach(item2 in array){
     *               if (item1 + item2 == target) {
     *                   return result
     *               }
     *           }
     *   ```
     *   
     *   We can see the nested loop just for searching, 
     *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
     *   (the map's `key` is the number, the `value` is the position)
     *   
     *   But be careful, if there are duplication numbers in array, 
     *   how the map store the positions for all of same numbers?
     *
     */


    //
    // The implementation as below is bit tricky. but not difficult to understand
    //
    //  1) Traverse the array one by one
    //  2) just put the `target - num[i]`(not `num[i]`) into the map
    //     so, when we checking the next num[i], if we found it is exisited in the map.
    //     which means we found the second one.
    //      
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            if (m.find(numbers[i])==m.end() ) { 
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i; 
            }else { 
                // found the second one
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
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
