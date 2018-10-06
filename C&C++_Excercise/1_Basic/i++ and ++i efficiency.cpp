/* i++ 和 ++i 的效率

1. 考虑内建类型时，效率差别不大，可以从汇编代码上看出
2. 但若考虑自定义数据类型（C++的类），前缀式(++i)返回对象的引用；而后缀式(i++)返回对象的值，大对象时会产生较大复制开销（local object） 
3. 具体见：
class INT;   
//++i 的版本   
INT INT::operator++()   
{   
    *this = *this + 1;   
    return *this;   
}   
//i++ 的版本   
const INT INT::operator ++(int)   
{   
    INT oldvalue = *this;   
    *this = *this + 1;   
    return oldvalue; 
}
*/

#include <stdio.h>

int main()
{
	int i = 0;
	int x = 0;
	
	i++;
	++i;
	x = i++;
	x = ++i;
	
	return 0;
}

