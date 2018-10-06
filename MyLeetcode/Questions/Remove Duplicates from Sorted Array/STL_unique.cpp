#include<algorithm>
#include<iostream>
#define MAXN 16

using namespace std;

int main() {
	int board[MAXN];
    int N;
    
    cin>>N; 
    for(int _=0 ; _<N ; _++) cin>>board[_]; 

    sort(board,board+N);
    int len = unique(board,board+N) - board;
    for(int _=0 ; _<len ; _++) cout<<board[_];
    
	return 0;
}

/*
INPUT: 6 >> N; 1 3 2 3 4 5 >> board;
OUTPUT: 12345
*/

// unique ����Ĳ�����sortһ������ȥ��֮ǰҪ����������һ����sort����ʹ�ã�
// unique ���ص���ȥ��֮���β��ַ�����Կ���ͨ����ȥ��ʼ��ַ���õ�ȥ�غ�ĳ��ȡ�
// unique ��αȥ����unique�����ظ���Ԫ�ط�����ǰ�������Ԫ�ر���unique����ǰ��״̬���䡣
// ��� unique �����ı�����Ԫ��λ�ã����ҿ��ܸı�ĳ����Ԫ�صĸ�������ͼƬ���� ��unique after sort.png�� 
