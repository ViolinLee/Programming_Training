#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cin >> str1;
    //����һ�����������
    string::iterator ptr1 = str1.begin();
    //��������ַ���
    while (ptr1 != str1.end())
        cout << *(ptr1++) << " ";
    cout << endl;

    cin >> str2;
    //����һ�����������
    string::reverse_iterator ptr2 = str2.rbegin();
    //��������ַ���
    while (ptr2 != str2.rend())
    //ע������������ƶ������෴�����Դ�β����Ȼͨ��++���ƶ�
        cout << *(ptr2++) << " ";
    cout << endl;
}

