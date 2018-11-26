struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
}

class Solution {
public:
	vector<Interval> insert(vector<Interval)& intervals, Interval newInterval) {
		vector<Interval> res;
		int n = intervals.size(), cur = 0;
		while (cur < n && intervals[cur].end < newInterval.start) { // 无重叠，且在newInterval左边 
			res.push_back(intervals[cur++]);
		}
		while (cur < n && intervals[cur].start <= newInterval.end) { // 开始有重叠-->逐一处理和更新 
			newInterval.start = min(newInterval.start, intervals[cur].start);
			newInterval.end = max(newInterval.end, intervals[cur].end);
			++cur;
		}
		res.push_back(newInterval);
		while (cur < n) { // 无重叠，且在newInterval右边 
			res.push_back(intervals[cur++]); 
		} 
		
	}
};

/*
注：重叠的情况有两种：
[     ]              [     ]
   [     ]         [    ]
两种情况的解决算法是一致的，即代码通用！ 
*/ 
