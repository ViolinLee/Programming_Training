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

template <class T>
struct chainNode
{
	//���ݳ�Ա
	T element;
	chainNode<T> *next; 
	
	//���� 
	chainNode() {}
	chainNode(const T& element)
	    {this->element = element;}
	chainNode(const T& element, chainNode<T>* next)
	    {this->element = element;
		 this->next = next;}
}; 
 
