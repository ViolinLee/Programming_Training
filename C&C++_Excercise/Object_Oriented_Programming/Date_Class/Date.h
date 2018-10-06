#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

// 不需要前置声明 

class Date
{
	public:
		Date(int y = 2000, int m = 1, int d = 1): year (y), month (m), day (d) { }
		
		// 操作符重载 
		Date& operator = (const Date&);
		 
		// 日期初始化函数 
		void setyear( int y ) { year = y; }
        void setmonth( int m ) { month = m; }
        void setday( int d ) { day = d; }
        
        // 获得数据 
		int getyear() const { return year; }
		int getmonth() const { return month; }
		int getday() const { return day; }
		
		//  print函数 
		void print() { cout<<year<<'-'<<month<<'-'<<day<<endl; }
	private:
		int year, month, day;
		
};

inline Date&
Date::operator = (const Date& r)
{
	this->year = r.year;
	this->month = r.month;
	this->day = r.day;
	return *this;
} 

inline bool
operator > (const Date& x, const Date& y)
{
	return (x.getyear() > y.getyear() 
	        || x.getyear() == y.getyear() && x.getmonth() > y.getmonth() 
			|| x.getyear() == y.getyear() && x.getmonth() == y.getmonth() && x.getday() > y.getday());
}

inline bool
operator < (const Date& x, const Date& y)
{
	return (x.getyear() < y.getyear() 
	        || x.getyear() == y.getyear() && x.getmonth() < y.getmonth() 
			|| x.getyear() == y.getyear() && x.getmonth() == y.getmonth() && x.getday() < y.getday());
}

inline bool
operator == (const Date& x, const Date& y)
{
	return (x.getyear() == y.getyear() && x.getmonth() == y.getmonth() && x.getday() == y.getday());
}

// isleap函数判断是否为闰年并返回bool值  
bool isleap(int year)
{
	if (year % 400 == 0 || year % 4 ==0 && year % 100 != 0)
        return true;
    return false;
 } 

#include <stdlib.h>

// 生成10个随机的Date 
Date* CreatePoints()
{
	Date *temp = new Date[10];
	
	for( int i=0; i<10; ++i)
	{
		temp[i].setyear( rand()%21 + 2000 );
		temp[i].setmonth( rand()%12 + 1 );
		
		int common[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		if (temp[i].getyear())
		{
			temp[i].setday( rand() % leap[temp[i].getmonth()] + 1 );
		}
		else
		{
			temp[i].setday( rand() % common[temp[i].getmonth()] + 1 );
		}
	}
	
	return temp;
	//这里应该要释放内存！！！
	//delete[] temp; 
}

// 使用冒泡算法对日期进行排序 
void Sort( Date *date )
{
	Date temp;
	for( int i=1; i<10; i++)
	{
		for( int j=0; j<10-i; j++)
		{
			if ( date[j] > date[j+1])
			{
				temp = date[j];
				date[j] = date[j+1];
				date[j+1] = temp;
			}
		}
	}
}

#endif
