// ��Ŀ����дһ��Sink��������ͬʱ�������inserter�������ʹ�ӡ��ֵ�Ĺ���

// ��׼���е�inserter��������һ����������������userʹ��insert_iterator���෴��insert_iteratorӰ��inserter�������Ϊ 
// inserter�������ķ���������insert_iterator,insert_iterator�Ǹ�adapter

/* inserterԴ�룺 
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

// ����Ϊsink������ 
template<class Container>
class sink_iterator:public iterator<output_iterator_tag,void,void,void,void>   // ������Ҫ�̳�iterator�����򽫱����Ҳ��� value type 
{
protected:
	Container* container;
	typename Container::iterator iter;
public:
	typedef output_iterator_tag iterator_category;
	
	sink_iterator(Container& x, typename Container::iterator i)
	:container(&x), iter(i){}    // ���캯����ĳ�ֵ�е��﷨������ 
	
	sink_iterator<Container>& operator=(const typename Container::value_type& value){ //Ϊʲôʹ��copyʱ�ͻ���� =�����أ���copyԴ�룡 
		iter = container->insert(iter, value);
		++iter;
		copy( container->begin(), container->end(), std::ostream_iterator<int> (std::cout, ","));  // ����copy��ӡ����Ԫ�� 
		cout << endl;
		return *this;}
	sink_iterator<Container>& operator* ()
    { return *this; }
    sink_iterator<Container>& operator++ ()
    { return *this; }
    sink_iterator<Container>& operator++ (int)
    { return *this; }
};

// ����Ϊsink����������sink������sink_iterator 
template<class Container, class Iterator>
inline sink_iterator<Container>
sink(Container& x, Iterator i){
	//copy( x.begin(), x.end(), std::ostream_iterator<int> (std::cout, ","));
	//cout << endl;
	return sink_iterator<Container>(x, typename Container::iterator(i));
} 

// ����Ϊ sink������ �Ĳ��� 
 
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
