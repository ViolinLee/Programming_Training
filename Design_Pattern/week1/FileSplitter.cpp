// 修改split()方法，使通过多态调用支持多种分割算法：virtual void DoSplit(const std::string &filePath, int fileNumber)  
// 运行时的分割算法由 MainForm 里的 TextBox *SplitterMethodID 决定 

#include<string>
#include<list>

class IProgress{
public:
	virtual void DoProgress(float value)=0;
	virtual ~IProgress(){}
};

// 改变：辅助函数 
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
	//改变 
    int MethodID;
	SplitterMethod* Method;
	
	List<IProgress*>  m_iprogressList; // 抽象通知机制，支持多个观察者
	
	//改变 
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

		//1.读取大文件
		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			//改变：多态调用 
            Method->DoSplit(filePath, i);
			
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);//发送通知
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
			(*itor)->DoProgress(value); //更新进度条
			itor++;
		}
	}
};

// 改变——SplitterMethod类和各个具体的分割算法 
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
    //分割算法1
}
};

class SplitterMethod2 :public SplitterMethod
{
public:
virtual void DoSplit(const std::string &filePath, int fileNumber)
{
    //分割算法2
}
};

class SplitterMethod3 :public SplitterMethod
{
public:
virtual void DoSplit(const std::string &filePath, int fileNumber)
{
    //分割算法3
}
}; 
