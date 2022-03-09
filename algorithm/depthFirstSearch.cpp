#include<iostream>

/*深度优先搜索的关键在于解决“当下该如何做”。至于“下一步该怎么做”则与“当下该如何做”是一样的。*/
/*
    基本模型
    void dfs(int step)
    {
        判断边界
        尝试每一种可能
        for(int i = 1; i < n; i++)
        {
            继续下一步
            dfs(step+1);
        }
        返回
    }
*/
using namespace std;
int a[10],book[10],n;

void dfs(int step)
{
    int i;
    if(step == n+1)
    {
        for (size_t i = 1; i <= n; i++)
        {
            /* code */
            cout <<a[i];
        }
        cout <<endl;
    }
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        if(book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return ;
}

int main()
{
    cin >>n;
    dfs(1);
    return 0;
    
}