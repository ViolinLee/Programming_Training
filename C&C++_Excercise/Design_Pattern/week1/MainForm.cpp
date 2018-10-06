// ԭ�������(�۲���ģʽ�μ�)�Ѿ�ʵ���˶�۲��ߣ����ڴ˻������޸Ĵ��룬ʹ֮�ڹ۲���ģʽ������֧�ֶ����ļ��ָ��㷨
// �ļ��ָ��㷨Ӧ���ǿ�����Ϊָ���ģ������MainForm����Ӧ��������ֶΣ����ﶨ��Ϊ TextBox *SplitterMethodID
// SplitterMethodIDֻ��һ��flag����Ҫ�и�������������ʽ��SplitterMethod���ø�������Ϊ FileSplitter����� class ISplitter 

#include<string>
#include"FileSplitter.h" 

class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	//�ı� 
    TextBox *SplitterMethodID;

	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());
		//�ı� 
        int MethodID = SplitterMethodID->getText(); 

		ConsoleNotifier cn;
        //�ı䣺splitter���Ӳ��� MethodID��������Ҫ�ں����FileSplitter��������Ӧ�޸� 
		FileSplitter splitter(filePath, number, MethodID);

		splitter.addIProgress(this); //����֪ͨ
		splitter.addIProgress(&cn)�� //����֪ͨ

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

