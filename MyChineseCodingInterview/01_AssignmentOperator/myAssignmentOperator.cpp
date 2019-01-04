class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	
	CMyString::operator = (const CMyString& str)
	
private:
	char* m_pData;
};

CMyString::CMyString(char* pData = nullptr) {  
	if (pData) this->m_pData = pData; //1.构造函数里不需要使用this指针 2.m_pData是指针类型，注意浅拷贝  3.strcpy函数 
	else m_pData = nullptr; // nullptr的情况？
}

CMyString::CMyString(const CMyString& str) {
	this->m_pData = str;
}

~CMyString::~CMyString() {
	delete[] m_pData;
}

CMyString::operator = (const CMyString& str) {
	
}
