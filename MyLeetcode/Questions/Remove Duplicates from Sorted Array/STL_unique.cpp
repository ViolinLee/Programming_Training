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

// unique 传入的参数和sort一样（在去重之前要先排序，所以一般与sort搭配使用）
// unique 返回的是去重之后的尾地址，所以可以通过减去开始地址来得到去重后的长度。
// unique 是伪去除。unique将不重复的元素放在最前，后面的元素保持unique操作前的状态不变。
// 因此 unique 不仅改变数组元素位置，而且可能改变某几个元素的个数。见图片资料 “unique after sort.png” 
