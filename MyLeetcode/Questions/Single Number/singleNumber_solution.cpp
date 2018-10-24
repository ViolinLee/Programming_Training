#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;
class Solution {
public:
	int singleNumber(vector<int>&  nums) {
		return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	}
};

int main() {
	int s[] = {1,1,2,3,2,4,4};
	vector<int> v(s, s+10);
	Solution solution;
	
	cout << solution.singleNumber(v);
		
	return 0;
}

/*
bit_xor: 预定义在参数上执行二进制和运算(二进制operator^)的函数对象。
accumulate: Returns the result of accumulating all the values in the range [first,last) to init. 结果是加上初始值init。
*/



/* bit_xor example
#include <iostream>     // std::cout
#include <functional>   // std::bit_xor
#include <algorithm>    // std::accumulate
#include <iterator>     // std::end

int main () {
  int flags[] = {1,2,3,4,5,6,7,8,9,10};
  int acc = std::accumulate (flags, std::end(flags), 0, std::bit_xor<int>());
  std::cout << "xor: " << acc << '\n';
  return 0;
}
*/
