struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
    }
};

/*我的思路： 
1.注意到给出的Interval具备性质：1）有序；2）不重叠 
2.找到最后一个小于或等于newInterval左边界的interval左边界，并记录其位置1
    若不存在：将intervals操作push_backinterval并返回
	若存在：从该位置开始，找到第一个大于等于newInterval右边界的interval右边界，并记录位置2 
	    若存在：假如左边界小于newInterval左边界，则舍去位置1至位置2的所有元素，并将newInterval插入位置1
		        假如左边界大于newInterval左边界，则舍去位置1至位置2前面的所有元素，并将newInterval插入位置1
	    若不存在：社区位置1至后面的所有数，并将newInterval插入位置1 
*/
