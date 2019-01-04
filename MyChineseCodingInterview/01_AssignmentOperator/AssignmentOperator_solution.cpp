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
		m_pData = new char[1]; // ��new char������
		m_pData[0] = '\0';
	} 
	else {
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(char *pData) // ���캯������CMyString�౾�� 
{
	
}

CMyString::~CMyString(void)
{
	
}

CMyString& operator = (const CMyString& str)
{
	
	return this;
}
