// �޸�split()������ʹͨ����̬����֧�ֶ��ַָ��㷨��virtual void DoSplit(const std::string &filePath, int fileNumber)  
// ����ʱ�ķָ��㷨�� MainForm ��� TextBox *SplitterMethodID ���� 

#include<string>
#include<list>

class IProgress{
public:
	virtual void DoProgress(float value)=0;
	virtual ~IProgress(){}
};

// �ı䣺�������� 
class ISplitter
{
public:
static SplitterStrategy* CreateSplitter(int MethodId)
{
    if (MethodId == 1) return new SplitterMethod1();
    if (MethodId == 2) return new SplitterMethod2();
    if (MethodId == 3) return new SplitterMethod3();
    return nullptr;
}
};

class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	//�ı� 
    int MethodID;
	SplitterMethod* Method;
	
	List<IProgress*>  m_iprogressList; // ����֪ͨ���ƣ�֧�ֶ���۲���
	
	//�ı� 
public:
	FileSplitter(const string& filePath, int fileNumber, int id) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber)
		MethodID(id)
	{
	    Method = ISplitter::CreateSplitter(id);
	}
	~FileSplitter()
    {
        delete Method;
        auto it = m_iProgresslist.begin();
        while (it != m_iProgresslist.end())
        {
            delete (*it);
            it++;
        }
        }


	void split(){

		//1.��ȡ���ļ�
		//2.��������С�ļ���д��
		for (int i = 0; i < m_fileNumber; i++){
			//...
			//�ı䣺��̬���� 
            Method->DoSplit(filePath, i);
			
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);//����֪ͨ
		}

	}

	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress);
	}

	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}


protected:
	virtual void onProgress(float value){
		
		List<IProgress*>::iterator itor=m_iprogressList.begin();

		while (itor != m_iprogressList.end() )
			(*itor)->DoProgress(value); //���½�����
			itor++;
		}
	}
};

// �ı䡪��SplitterMethod��͸�������ķָ��㷨 
class SplitterMethod
{
public:
virtual void DoSplit(const std::string &filePath, int fileNumber) = 0;
virtual ~SplitterMethod() = 0;
};

class SplitterMethod1:public SplitterMethod
{
public:
    virtual void DoSplit(const std::string &filePath, int fileNumber)
{
    //�ָ��㷨1
}
};

class SplitterMethod2 :public SplitterMethod
{
public:
virtual void DoSplit(const std::string &filePath, int fileNumber)
{
    //�ָ��㷨2
}
};

class SplitterMethod3 :public SplitterMethod
{
public:
virtual void DoSplit(const std::string &filePath, int fileNumber)
{
    //�ָ��㷨3
}
}; 
