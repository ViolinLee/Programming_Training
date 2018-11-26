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
		while (cur < n && intervals[cur].end < newInterval.start) { // ���ص�������newInterval��� 
			res.push_back(intervals[cur++]);
		}
		while (cur < n && intervals[cur].start <= newInterval.end) { // ��ʼ���ص�-->��һ����͸��� 
			newInterval.start = min(newInterval.start, intervals[cur].start);
			newInterval.end = max(newInterval.end, intervals[cur].end);
			++cur;
		}
		res.push_back(newInterval);
		while (cur < n) { // ���ص�������newInterval�ұ� 
			res.push_back(intervals[cur++]); 
		} 
		
	}
};

/*
ע���ص�����������֣�
[     ]              [     ]
   [     ]         [    ]
��������Ľ���㷨��һ�µģ�������ͨ�ã� 
*/ 
