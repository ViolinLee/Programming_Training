/*
back_inserter������һ��ʹ��push_back�ĵ����� 
inserter���˺������ܵڶ����������������������һ��ָ����������ĵ�������Ԫ�ؽ������뵽��������������ʾ��Ԫ��֮ǰ�� 
front_inserter������һ��ʹ��push_front�ĵ�������Ԫ�����ǲ��뵽������һ��Ԫ��֮ǰ�� 
*/

list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
list<int> lst2 ={10}, lst3={10},lst4={10};
copy(lst.cbegin(), lst.cend(), back_inserter(lst2));
//lst2����10,1,2,3,4,5,6,7,8,9
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
//lst3����1,2,3,4,5,6,7,8,9,10
copy(lst.cbegin(), lst.cend(), front_inserter(lst4));
//lst4����9,8,7,6,5,4,3,2,1,10

