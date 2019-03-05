#include<iostream>
using namespace std;

//值传递
 void change1(int n){
    cout<<"值传递--函数操作地址"<<&n<<endl;  //显示的是拷贝的地址而不是源地址 
    n++;
}

//引用传递
void change2(int & n){
    cout<<"引用传递--函数操作地址"<<&n<<endl; 
    n++;
}

//指针传递
void change3(int *n){
     cout<<"指针传递--函数操作地址 "<<n<<endl; 
    *n=*n+1;
}

int main(){
    int n=10;
    cout<<"实参的地址"<<&n<<endl;
    change1(n);
    cout<<"after change1() n="<<n<<endl;
    change2(n); // 引用传递，传实参的形式是和值传递完全一致的 
    cout<<"after change2() n="<<n<<endl;
    change3(&n); // 指针传递，实参必须为指针的值（即对变量取地址） 
    cout<<"after change3() n="<<n<<endl;
    return true;
}

