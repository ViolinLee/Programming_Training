// unique ��� vector.erase ɾ���ظ�Ԫ�� 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 1000;
int a[N + 5];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0;i < n;++i) scanf("%d",&a[i]);
        sort (a, a + n);
        vector<int>v (a, a + n);
        vector<int>::iterator it = unique (v.begin(), v.end() );
        v.erase (it, v.end() );//������ǰѺ�����������ظ�Ԫ��ɾ����
        for ( it = v.begin() ; it != v.end() ; it++ )
        {
            printf ("%d ", *it);
        }
        puts("");
    }
    return 0;
}

