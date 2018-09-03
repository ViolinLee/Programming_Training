// 程序差错——参数引用
 
#include <iostream> 
using namespace std; 

const float pi=3.14f;
float f; 

float f1(float r){  // f1()返回的是全局变量f的值（会隐式地建立临时变量temp） 
	f = r*r*pi; // 函数内直接操作全局变量 
	
	return f; // 返回时是返回一个copy 
}
float& f2(float r){ // f2()返回的是全局变量f的引用（f的别名） 
	f = r*r*pi; // 函数内直接操作全局变量 
	
	return f; // 返回时直接返回全局变量的引用 
}

int main(){
	float f1(float=5); // 正确。声明函数f1()的 “默认参数调用”，其默认参数值为5 
	float& f2(float=5); // 正确。声明函数f2()的 “默认参数调用”，其默认参数值为5 
	
	float a=f1();  // 正确。将变量a赋值为f1()的返回值 
	float& b=f1(); // 错误。将变量b赋值为f1()的返回值-->在f1()函数里，全局变量f的值78.5赋值给临时变量temp，然后建立temp的引用（不能引用临时变量！）
	 
	float c=f2();  // 正确。f2()返回值时并没有隐式建立临时变量temp，而是直接将全局变量f返回给主函数 
	float& d=f2(); // 正确。主函数中都不使用定义变量，而是直接使用全局变量的引用，这种方式是全部4种最节省内容空间的
	               // 但必须注意它所引用的变量的有效期，此处全局变量f的有效期肯定长与引用d，所以是安全的
	
	d += 1.0f; // 正确。将d的值加1.0，此时d是全局变量f的引用 
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "f = " << f << endl;
	
	return 0;
}
