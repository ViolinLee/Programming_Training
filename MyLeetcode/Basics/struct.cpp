#include<iostream>

using namespace std;

/* 1.先声明结构体类型再定义变量名（最常用的一种方法） 
int main(){
    struct Student{
	    int num;
	    char name[20];
	    char sex;
	    int age;
	    float score;
	    char addr[30];
    };

    Student student1, student2;
    cout << sizeof(Student) << endl;
    cout << sizeof(student1) << endl;
    cout << sizeof(student2) << endl;
    return 0;
} */ 


/* 2.在声明类型的同时定义变量 
int main(){
    struct Student{
	    int num;
	    char name[20];
	    char sex;
	    int age;
	    float score;
	    char addr[30];
    }student1, student2;
    
    cout << sizeof(Student) << endl;
    cout << sizeof(student1) << endl;
    cout << sizeof(student2) << endl;
    return 0;
}
*/


/* 3.直接定义结构体类型变量（这种定义方法虽然合法，但是不常用） 
int main(){
    struct {
	    int num;
	    char name[20];
	    char sex;
	    int age;
	    float score;
	    char addr[30];
    }student1, student2;
    
    cout << sizeof(student1) << endl;
    cout << sizeof(student2) << endl;
    return 0;
}
*/ 

struct Date{
	int month;
	int day;
	int year;
}; 
struct Student{
	int num;
	char name[20];
	char sex;
	int age;
	Date birthday;
	float score;
	char addr[30];
};

int main(){
	/* 
	Student two={1, "qianshou", 'm', 19, 10, 01, 1993, 100, "JiNan"};
	Student one = two; // 相同类型结构体变量可以直接赋值 
	cout << one.num << endl;
	cout << one.name << endl;
	cout << one.sex << endl;
	cout << one.age << endl;
	cout << one.birthday.month << "/" << one.birthday.day << "/" << one.birthday.year << endl;
	cout << one.score << endl;
	cout << one.addr << endl;
	*/
	
	Student two={1, "qianshou", 'm', 19, 10, 01, 1993, 100, "JiNan"};
	Student &one = two; // 怎么理解？ 定义了一个 "Student类型地址" 变量one，one的值是two的地址
	                    // 这里是定义了引用（引用必须在定义的同时进行初始化）。 
 
	one.num++; // 引用和原对象的使用在语法上没有差别 
	one.birthday.day += 10;
	cout << two.num << endl;
	cout << two.name << endl;
	cout << two.sex << endl;
	cout << two.age << endl;
	cout << two.birthday.month << "/" << one.birthday.day << "/" << one.birthday.year << endl;
	cout << two.score << endl;
	cout << two.addr << endl; 
	
	
	return 0;
}
