/* 
����ڵ�Ľṹ���壺 
1.���ݳ�Ա��
    �ڵ����� next: �洢��һ���ڵ��ָ�� 
    �ڵ������� element���洢��Ԫ�� 
2.������
    �������캯��
3.ע�⣺
    ģ����� 
*/

// chain node

#ifndef chainNode_
#define chainNode_

template <class T>
struct chainNode
{
	// data members
	T element;
	chainNode<T> *next; 
	
	// methods 
	chainNode() {}
	chainNode(const T& element)
	    {this->element = element;}
	chainNode(const T& element, chainNode<T>* next)
	    {this->element = element;
		 this->next = next;}
}; 

#endif

