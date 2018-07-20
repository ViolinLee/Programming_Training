#include<iostream>  
#include<list>  
#include<vector>
#include<math.h>    
  
using namespace std;  
  
int main()  
{  
    list<int> testlist = {0,1,30,20,10,0}; // 标准答案出现新知识点：list<int>::reverse_iterator,并考察rebegin和rend 
    list<int>::iterator list_ite;

    cout << "1.从后向前打印" << endl;
    for (list_ite = --testlist.end();list_ite!=--testlist.begin();--list_ite){
    	cout << *list_ite << " ";
	}
	
	cout << "\n"<< "\n" << "2.向list添加元素并求和" << endl;
	cout << "输入两个int型数字,以空格区分: ";
	int a,b,sum;
	cin >> a >> b;
	testlist.push_back(a);
	testlist.push_back(b);
	for (auto& list_value : testlist){  // 参考答案使用accumulate函数来求和 
		sum+=list_value;
	}
	cout << "元素的和为: " << sum << endl<< "\n";
    
    cout << "3.打印链表中间元素" << endl;  // 参考答案使用advance函数 
	int num,medium;
	num = ceil(testlist.size() / 2);
	list_ite = testlist.begin();
	for (int i=num;i>0;--i){
		++ list_ite;
	}
	medium = *(--list_ite);
	cout << "中间元素为: " << medium << endl<< "\n";
	
    vector<int> testvec;
    vector<int>::iterator vec_ite;
    cout << "4.查找list中不为0的元素。复制到一个vector中并打印vector元素" << endl;  
    for (auto list_value : testlist)  
    {  
        if (list_value != 0)  
        {  
            testvec.push_back(list_value);   // 逐个push_back符合条件的元素，最不可取，效率不高 
        }  
    }  
    cout << "vector中的元素为：";  
    for (auto vec_value : testvec)  
    {  
        cout << vec_value << "  ";  
    }  		 
	cout << endl;
	
	return 0;  
}

