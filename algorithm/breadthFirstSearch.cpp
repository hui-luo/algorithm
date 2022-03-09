#iclude<iostream>

using namespace std;
struct note
{
    /* data */
    int x;
    int y;
    int f;
    int s;
};


int main()
{
    struct note que[2501];
    int a[51][51] = {0}, book[51][51] = {0};
    //定义一个用于表示走的方向的数组
    int next[4][2] = {{0,1}, 
                      {1,0},
                      {0,-1},
                      {-1,0}};
    int head,tail;
    int i,j,k,m,n,startx,starty,p,q,tx,ty,flag;
    cin >>n >>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >>a[i][j];
        }
    }
    cin >>startx >>starty >>p >>q;
    //队列的初始化
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startx][starty] = 1;
    flag = 0;       //用来标记是否到达目标点，0表示暂时没有到达，1表示到达
    while (head < tail)
    {
        /* code */
        for ( k = 0; k <= 3; k++)
        {
            /* code */
            tx = que[head].x+next[k][0];
            ty = que[head].y+next[k][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m)  //判断是否越界
                continue;
            if (a[tx][ty] == 0 && book[tx][ty] == 0)  //判断是否为障碍物或者已经在队列中
            {
                book[tx][ty] = 1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;
                que[tail].s=que[head].s+1;
            }
            if (tx == p && ty == q)
            {
                /* code */
                flag = 1;
                break;
            }
            
            
        }
        
    }
    
}