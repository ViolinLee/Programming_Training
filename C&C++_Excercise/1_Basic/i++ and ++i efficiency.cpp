/* i++ �� ++i ��Ч��

1. �����ڽ�����ʱ��Ч�ʲ�𲻴󣬿��Դӻ������Ͽ���
2. ���������Զ����������ͣ�C++���ࣩ��ǰ׺ʽ(++i)���ض�������ã�����׺ʽ(i++)���ض����ֵ�������ʱ������ϴ��ƿ�����local object�� 
3. �������
class INT;   
//++i �İ汾   
INT INT::operator++()   
{   
    *this = *this + 1;   
    return *this;   
}   
//i++ �İ汾   
const INT INT::operator ++(int)   
{   
    INT oldvalue = *this;   
    *this = *this + 1;   
    return oldvalue; 
}
*/

#include <stdio.h>

int main()
{
	int i = 0;
	int x = 0;
	
	i++;
	++i;
	x = i++;
	x = ++i;
	
	return 0;
}

