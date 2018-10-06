// unique 结合 vector.erase 删除重复元素 
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
        v.erase (it, v.end() );//这里就是把后面藏起来的重复元素删除了
        for ( it = v.begin() ; it != v.end() ; it++ )
        {
            printf ("%d ", *it);
        }
        puts("");
    }
    return 0;
}

