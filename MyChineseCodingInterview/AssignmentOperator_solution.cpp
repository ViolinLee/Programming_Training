#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char *pData) // ���캯������C����ַ��� 
{
	if (pData == nullptr) {
		
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
