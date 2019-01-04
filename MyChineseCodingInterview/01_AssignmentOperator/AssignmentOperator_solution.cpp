#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str); // operator = 的返回类型 

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char *pData) // 构造函数传入C风格字符串 
{
	if (pData == nullptr) {
<<<<<<< HEAD:MyChineseCodingInterview/01_AssignmentOperator/AssignmentOperator_solution.cpp
		m_pData = new char[1]; // 与new char无区别
		m_pData[0] = '\0';
	} 
	else {
=======
		m_pData = new char[1]; // 同 new char效果一致
		m_pData[0] = '\0'; 
	} else {
>>>>>>> 60f6e02cb36c19390315703c79f0dd9aef7669e1:MyChineseCodingInterview/AssignmentOperator_solution.cpp
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str) // 构造函数传入CMyString类本身 
{
	int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString& str)
{
	if(this == &str)
	    return *this;
	    
	delete[] m_pData; // 先释放再申请 
	m_pData = nullptr; // 避免野指针(注意和空指针区别)；此处并不必须 
	
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	
	return *this;
}

// =================Test Code================
void CMyString::Print() {
	printf("%s", m_pData);
}

// 构造函数传入C风格字符串; 赋值运算符 
void Test1() {
	printf("Test1 begins:\n");
	
	char* text = "Hello world";
	
	CMyString str1(text);
	CMyString str2;
	str2 = str1;
	
	printf("The expected result is: %s.\n", text);
	
    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己 
void Test2() {
	printf("Test2 begins:\n");
	
	char* text = "Hello world";
	
	CMyString str1(text);
	str1 = str1;
	
	printf("The expected result is: %s.\n", text);
	
	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3() {
	printf("Test3 begins:\n");
	
	char* text = "Hello world";
	
	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;
	
	printf("The expected result is: %s.\n", text);
	
	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
	
	printf("The actual result is: ");
    str3.Print();
    printf(".\n");
} 

int main(int argc, char* argv[]) {
	Test1();
	Test2();
	Test3();
	
	return 0;
}
