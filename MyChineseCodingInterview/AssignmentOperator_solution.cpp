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

CMyString::CMyString(char *pData) // 构造函数传入C风格字符串 
{
	if (pData == nullptr) {
		
	} 
}

CMyString::CMyString(char *pData) // 构造函数传入CMyString类本身 
{
	
}

CMyString::~CMyString(void)
{
	
}

CMyString& operator = (const CMyString& str)
{
	
	return this;
}
