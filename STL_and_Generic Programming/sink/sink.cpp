// 题目；编写一个Sink迭代器，同时可以完成inserter迭代器和打印数值的功能

// 标准库中的inserter迭代器是一个辅助函数，帮助user使用insert_iterator；相反的insert_iterator影响inserter对外的行为 
// inserter迭代器的返回类型是insert_iterator,insert_iterator是个adapter

/* inserter源码： 
template<class Container, class Iterator>
inline insert_iterator<Container>
inserter(Container& x, Iterator i){
	typedef typename Container::iterator iter;
	return insert_iterator<Container>(x, iter(i));
}
*/

#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

// 以下为sink迭代器 
template<class Container>
class sink_iterator:public iterator<output_iterator_tag,void,void,void,void>   // 这里需要继承iterator，否则将报错找不到 value type 
{
protected:
	Container* container;
	typename Container::iterator iter;
public:
	typedef output_iterator_tag iterator_category;
	
	sink_iterator(Container& x, typename Container::iterator i)
	:container(&x), iter(i){}    // 构造函数里的初值列的语法不能忘 
	
	sink_iterator<Container>& operator=(const typename Container::value_type& value){ //为什么使用copy时就会调用 =重载呢？看copy源码！ 
		iter = container->insert(iter, value);
		++iter;
		copy( container->begin(), container->end(), std::ostream_iterator<int> (std::cout, ","));  // 利用copy打印容器元素 
		cout << endl;
		return *this;}
	sink_iterator<Container>& operator* ()
    { return *this; }
    sink_iterator<Container>& operator++ ()
    { return *this; }
    sink_iterator<Container>& operator++ (int)
    { return *this; }
};

// 以下为sink函数，返回sink迭代器sink_iterator 
template<class Container, class Iterator>
inline sink_iterator<Container>
sink(Container& x, Iterator i){
	//copy( x.begin(), x.end(), std::ostream_iterator<int> (std::cout, ","));
	//cout << endl;
	return sink_iterator<Container>(x, typename Container::iterator(i));
} 

// 以下为 sink迭代器 的测试 
 
int main(){
	list<int> foo, bar;
	for(int i=1;i<=5;++i){
		foo.push_back(i);
		bar.push_back(i*10);
	} 
	
	list<int>::iterator it = foo.begin();
	advance(it,3);
	
	copy(bar.begin(), bar.end(), sink(foo,it));
	return 0;
}
