#include<iostream>

using namespace std;

/* 1.�������ṹ�������ٶ������������õ�һ�ַ����� 
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


/* 2.���������͵�ͬʱ������� 
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


/* 3.ֱ�Ӷ���ṹ�����ͱ��������ֶ��巽����Ȼ�Ϸ������ǲ����ã� 
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
	Student one = two; // ��ͬ���ͽṹ���������ֱ�Ӹ�ֵ 
	cout << one.num << endl;
	cout << one.name << endl;
	cout << one.sex << endl;
	cout << one.age << endl;
	cout << one.birthday.month << "/" << one.birthday.day << "/" << one.birthday.year << endl;
	cout << one.score << endl;
	cout << one.addr << endl;
	*/
	
	Student two={1, "qianshou", 'm', 19, 10, 01, 1993, 100, "JiNan"};
	Student &one = two; // ��ô��⣿ ������һ�� "Student���͵�ַ" ����one��one��ֵ��two�ĵ�ַ
	                    // �����Ƕ��������ã����ñ����ڶ����ͬʱ���г�ʼ������ 
 
	one.num++; // ���ú�ԭ�����ʹ�����﷨��û�в�� 
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
