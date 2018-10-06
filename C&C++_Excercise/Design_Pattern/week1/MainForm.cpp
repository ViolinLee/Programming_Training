// 原来的软件(观察者模式课件)已经实现了多观察者，可在此基础上修改代码，使之在观察者模式基础上支持多种文件分割算法
// 文件分割算法应该是可以人为指定的，因此在MainForm里面应该有相关字段，这里定义为 TextBox *SplitterMethodID
// SplitterMethodID只是一个flag，需要有辅助函数生成正式的SplitterMethod，该辅助函数为 FileSplitter里面的 class ISplitter 

#include<string>
#include"FileSplitter.h" 

class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	//改变 
    TextBox *SplitterMethodID;

	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		//改变 
        int MethodID = SplitterMethodID->getText(); 

		ConsoleNotifier cn;
        //改变：splitter增加参数 MethodID；所以需要在后面的FileSplitter类中做相应修改 
		FileSplitter splitter(filePath, number, MethodID);

		splitter.addIProgress(this); //订阅通知
		splitter.addIProgress(&cn)； //订阅通知

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};

