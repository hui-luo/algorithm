#include<iostream>

using namespace std;
int fun(int x)
{
    int num=0;
    int f[10] = {6,2,5,5,4,5,6,3,7,6};
    while(x/10 != 0)
    {
        num +=f[x%10];
        x /= 10;
    }
    num += f[x];
    return num;
} 

int main()
{
    int a,b,c,m,sum = 0;
    cout<<"请输入火柴棍的数目：";
    cin >>m;
    for(a = 0; a <= 1111; a++)
    {
        for(b=0; b <= 1111; b++)
        {
            c = a + b;
            if (fun(c) + fun(b) + fun(a) == m-4)
            {
                /* code */
                cout <<a <<'+' <<b <<'=' <<c <<endl;
                sum++;
            }
            
        }
    }
    cout <<"一共有" <<sum <<"个不同的不等式" <<endl;
}