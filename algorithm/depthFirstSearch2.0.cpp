#include<iostream>
using namespace std;
int n,m,p,q;
int Min = 9999;
int a[51][51],book[51][51];

void dfs(int x, int y, int step)
{
    int next[4][2] = {{0,1},
                      {1,0},
                      {0,-1},
                      {-1,0}};
    int tx,ty,k;
    if(x == p && y == q)
    {
        if(step < Min)
        {
             Min = step;
        }
        return ;
    }
    for(k=0; k <= 3; k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m)
        {
            continue;
        }
        if(a[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            dfs(tx,ty,step+1);
            book[tx][ty] = 0;
        } 
    }
    return ;
}

int main()
{
    int i,j,startx,starty;
    cin >> n >>m;
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        for (size_t j = 1; j <= m; j++)
        {
            /* code */
            cin >> a[i][j];
        }
    }
    cin >>startx >>starty >>p >>q;
    book[startx][starty] = 1;
    dfs(startx,starty,0);
    cout << Min <<endl;
}