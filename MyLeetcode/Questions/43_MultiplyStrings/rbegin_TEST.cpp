#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cin >> str1;
    //定义一个正向迭代器
    string::iterator ptr1 = str1.begin();
    //正向输出字符串
    while (ptr1 != str1.end())
        cout << *(ptr1++) << " ";
    cout << endl;

    cin >> str2;
    //定义一个逆向迭代器
    string::reverse_iterator ptr2 = str2.rbegin();
    //逆向输出字符串
    while (ptr2 != str2.rend())
    //注意逆向迭代器移动方向相反，所以从尾部仍然通过++来移动
        cout << *(ptr2++) << " ";
    cout << endl;
}

