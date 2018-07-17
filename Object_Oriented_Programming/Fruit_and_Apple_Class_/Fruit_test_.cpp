// Ϊ������Ŀ�е� Fruit��Apple ��� ���캯���� ���������� 
// ���ڹ��캯�������������д�ӡ����̨��Ϣ���۲칹������۵��ù��̡�
// Ȼ��ΪApple������ ::operator new �� ::operator delete���ڿ���̨��ӡ��Ϣ�����۲���ý����

#include <iostream>
#include "Fruit_.h"

using namespace std;

int main(){
	cout << "******************** Test 1 ********************" << endl;
	Apple* a = new Apple;     
	delete a;    // ��������������������������virtual��Ҳ������� memory leak 
	Apple* A = new Apple[2];
	delete[] A;  // �˴�Ӧ����array delete����������ڴ�й¶ 
	
	cout << endl;
	cout << "******************** Test 2 ********************" << endl;
	Fruit* f = new Apple;
	delete f;    // ��������������������virtual����ֻ���ø���������������������������������������ڴ�й¶
	Fruit* F = new Apple[2];  
	delete[] F;  // �����жϣ����� ��VC�ϲ��ᣡ���� 
	
	return 0;
}


// ע�⵽����̨�Ĵ�ӡ��Ϣ��
// ��new��������ʱ���ȵ���operator new�����ռ䣬�ٵ��ù��캯���� 
// ��deleteɾ������ʱ���ȵ��������������ٵ���operator delete�ͷ��ڴ档


// �ڲ����Ե��ù�ϵ��
// new -> (operator new -> malloc) + ���캯��      
// delete -> �������� + (operator delete -> free)

  
// operator new���ڲ�����malloc�����ڴ棻
// operator delete���ڲ�����free�ͷ��ڴ档 

