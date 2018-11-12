// 思路：两层for，内层用set

#include <iostream>
#include <vector>
#include <set>

using namespace std;
Class Solution {
public:
	vector<vector<int>> threeSum(&nums<int>) { // 函数接口？返回下标而且可能不止一组 
	    vector<vector<int>> res;
		int n = nums.size();
	    set<int> s(nums);
	    
	    for (int i=0; i<n; i++) {
	    	for (int j=0; j<n; j++) { // 注意不考虑重复元素 
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


/* 两重循环（此处用set的方法）怎么避免重复解（判重+元素重）？删除元素？改变值？
1.跳过重复元素-->可以先排序，然后每次比较相邻的两个数 
2.删除重复结果-->用数据结构 map () 
*/ 
 
