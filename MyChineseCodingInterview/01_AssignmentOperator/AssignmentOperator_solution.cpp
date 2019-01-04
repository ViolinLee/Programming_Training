#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str); // operator = �ķ������� 

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char *pData) // ���캯������C����ַ��� 
{
	if (pData == nullptr) {
<<<<<<< HEAD:MyChineseCodingInterview/01_AssignmentOperator/AssignmentOperator_solution.cpp
		m_pData = new char[1]; // ��new char������
		m_pData[0] = '\0';
	} 
	else {
=======
		m_pData = new char[1]; // ͬ new charЧ��һ��
		m_pData[0] = '\0'; 
	} else {
>>>>>>> 60f6e02cb36c19390315703c79f0dd9aef7669e1:MyChineseCodingInterview/AssignmentOperator_solution.cpp
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str) // ���캯������CMyString�౾�� 
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
	    
	delete[] m_pData; // ���ͷ������� 
	m_pData = nullptr; // ����Ұָ��(ע��Ϳ�ָ������)���˴��������� 
	
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	
	return *this;
}

// =================Test Code================
void CMyString::Print() {
	printf("%s", m_pData);
}

// ���캯������C����ַ���; ��ֵ����� 
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

// ��ֵ���Լ� 
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

// ������ֵ
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
