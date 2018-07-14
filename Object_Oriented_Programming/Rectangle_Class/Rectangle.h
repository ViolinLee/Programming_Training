#ifndef __MYRECTANGLE__
#define __MYRECTANGLE__

class Shape
{                   
    int no;
};
              
class Point
{
private:
    int x;
    int y;
public:
    Point(int x1 = 0, int y1 = 0): x(x1), y(y1) { }
	int get_x() const { return x;}
	int get_y() const { return y;}
};

class Rectangle: public Shape
{
private:   
    int width;
    int height;
    Point * leftUp;
public:
    Rectangle(int w, int h, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle();
    int get_width() const { return width;}  
    int get_height() const { return height;} 
    Point* get_leftUp() const { return leftUp;}      
};

inline
Rectangle::Rectangle(int w = 0, int h = 0, int x = 0, int y = 0): width (w), height (h), leftUp (new Point (x,y)) { }
 
inline
Rectangle::~Rectangle()
{
	delete leftUp;    // new的对象是指针，不是array new 
}

inline
Rectangle::Rectangle(const Rectangle& other): width(other.width), height(other.height)
{
    leftUp = new Point(*(other.leftUp));    // 创建一个Point，并赋值 
}

inline
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this == &other)   //检测自我赋值 
	    return *this;
	
	delete leftUp;      // 这是只delete掉Rectangle对象的leftUp数据，width和height的数据还保留着
	width = other.width;     
	height = other.height;
	leftUp = new Point(*(other.leftUp));
	return *this;
 } 
 
 #include <iostream>
 using namespace std;
 
 ostream& operator<<(ostream& os, const Rectangle& rec)
 {
 	os << "(" << rec.get_width() << "," << rec.get_height() << "," << rec.get_leftUp()->get_x() << "," << rec.get_leftUp()->get_y() << ")" << endl;
 	return os;
 }

#endif 
