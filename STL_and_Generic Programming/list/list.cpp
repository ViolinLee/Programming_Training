#include<iostream>  
#include<list>  
#include<vector>
#include<math.h>    
  
using namespace std;  
  
int main()  
{  
    list<int> testlist = {0,1,30,20,10,0}; // ��׼�𰸳�����֪ʶ�㣺list<int>::reverse_iterator,������rebegin��rend 
    list<int>::iterator list_ite;

    cout << "1.�Ӻ���ǰ��ӡ" << endl;
    for (list_ite = --testlist.end();list_ite!=--testlist.begin();--list_ite){
    	cout << *list_ite << " ";
	}
	
	cout << "\n"<< "\n" << "2.��list���Ԫ�ز����" << endl;
	cout << "��������int������,�Կո�����: ";
	int a,b,sum;
	cin >> a >> b;
	testlist.push_back(a);
	testlist.push_back(b);
	for (auto& list_value : testlist){  // �ο���ʹ��accumulate��������� 
		sum+=list_value;
	}
	cout << "Ԫ�صĺ�Ϊ: " << sum << endl<< "\n";
    
    cout << "3.��ӡ�����м�Ԫ��" << endl;  // �ο���ʹ��advance���� 
	int num,medium;
	num = ceil(testlist.size() / 2);
	list_ite = testlist.begin();
	for (int i=num;i>0;--i){
		++ list_ite;
	}
	medium = *(--list_ite);
	cout << "�м�Ԫ��Ϊ: " << medium << endl<< "\n";
	
    vector<int> testvec;
    vector<int>::iterator vec_ite;
    cout << "4.����list�в�Ϊ0��Ԫ�ء����Ƶ�һ��vector�в���ӡvectorԪ��" << endl;  
    for (auto list_value : testlist)  
    {  
        if (list_value != 0)  
        {  
            testvec.push_back(list_value);   // ���push_back����������Ԫ�أ����ȡ��Ч�ʲ��� 
        }  
    }  
    cout << "vector�е�Ԫ��Ϊ��";  
    for (auto vec_value : testvec)  
    {  
        cout << vec_value << "  ";  
    }  		 
	cout << endl;
	
	return 0;  
}

