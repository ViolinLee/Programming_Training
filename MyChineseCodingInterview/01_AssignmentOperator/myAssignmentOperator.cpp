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
	if (pData) this->m_pData = pData; //1.���캯���ﲻ��Ҫʹ��thisָ�� 2.m_pData��ָ�����ͣ�ע��ǳ����  3.strcpy���� 
	else m_pData = nullptr; // nullptr�������
}

CMyString::CMyString(const CMyString& str) {
	this->m_pData = str;
}

~CMyString::~CMyString() {
	delete[] m_pData;
}

CMyString::operator = (const CMyString& str) {
	
}
