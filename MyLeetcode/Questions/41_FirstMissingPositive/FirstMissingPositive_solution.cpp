#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/* �����޶���O(n)��ʱ�䣬����һ������򷽷���������*/

// NOT constant space(û��ʹ�����򣬵��ǳ����ռ䣬)
class Solution_bad {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> s;
        for (int num : nums) {
            if (num <= 0) continue;
            s.insert(num);
            mx = max(mx, num); // ʹ��hashset���ҳ�max value���᲻��set���ã�set���������Ԫ�� 
        }
        for (int i = 1; i <= mx; ++i) {
            if (!s.count(i)) return i;
        }
        return mx + 1;
    }
};

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) { //������ȷλ�õ���һ������!!! 
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] -1] != nums[i]) { //nums[i] <= n���Ա���nums[nums[i] - 1]Խ�� 
				swap(nums[i], nums[nums[i] - 1]); // ̫������... 
			}
		}
		
		for (auto n : nums) cout << n << " "; // test the "for-while" result
		
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
}; 

int main() {
	Solution solution;
	vector<int> test = {7, 5, 2, 1, 3}; // ����������ȷλ�ñ�� 1 2 3 7 5 
	cout << endl << solution.firstMissingPositive(test);
	
	return 0;
}



/*
�ؼ���whileѭ��
��� nums[i] > n ��ֱ�������� 
*/
