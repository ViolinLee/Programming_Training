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

/*�ҵ�˼·�� 
1.ע�⵽������Interval�߱����ʣ�1������2�����ص� 
2.�ҵ����һ��С�ڻ����newInterval��߽��interval��߽磬����¼��λ��1
    �������ڣ���intervals����push_backinterval������
	�����ڣ��Ӹ�λ�ÿ�ʼ���ҵ���һ�����ڵ���newInterval�ұ߽��interval�ұ߽磬����¼λ��2 
	    �����ڣ�������߽�С��newInterval��߽磬����ȥλ��1��λ��2������Ԫ�أ�����newInterval����λ��1
		        ������߽����newInterval��߽磬����ȥλ��1��λ��2ǰ�������Ԫ�أ�����newInterval����λ��1
	    �������ڣ�����λ��1�������������������newInterval����λ��1 
*/
