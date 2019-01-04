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
		m_pData = new char[1]; // 与new char无区别
		m_pData[0] = '\0';
	} 
	else {
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
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
