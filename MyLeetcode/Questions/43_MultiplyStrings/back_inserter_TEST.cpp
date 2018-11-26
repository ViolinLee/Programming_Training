/*
back_inserter：创建一个使用push_back的迭代器 
inserter：此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。 
front_inserter：创建一个使用push_front的迭代器（元素总是插入到容器第一个元素之前） 
*/

list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
list<int> lst2 ={10}, lst3={10},lst4={10};
copy(lst.cbegin(), lst.cend(), back_inserter(lst2));
//lst2包含10,1,2,3,4,5,6,7,8,9
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
//lst3包含1,2,3,4,5,6,7,8,9,10
copy(lst.cbegin(), lst.cend(), front_inserter(lst4));
//lst4包含9,8,7,6,5,4,3,2,1,10

