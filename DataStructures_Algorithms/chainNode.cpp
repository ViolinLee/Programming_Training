/* 
链表节点的结构定义： 
1.数据成员：
    节点链域 next: 存储下一个节点的指针 
    节点数据域 element：存储表元素 
2.方法：
    三个构造函数
3.注意：
    模板参数 
*/

template <class T>
struct chainNode
{
	//数据成员
	T element;
	chainNode<T> *next; 
	
	//方法 
	chainNode() {}
	chainNode(const T& element)
	    {this->element = element;}
	chainNode(const T& element, chainNode<T>* next)
	    {this->element = element;
		 this->next = next;}
}; 
 
