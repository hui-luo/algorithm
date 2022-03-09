#include<iostream>

using namespace std;

void quicksort1(int array[],int left,int right);         //正序排序
void quicksort2(int array[],int left,int right);         //倒序排序

int main ()
{

    int array[6];
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cin >>array[i];
    }
    
    quicksort1(array,0,5);
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout <<array[i] <<" ";
    }

    cout<<endl;

    quicksort2(array,0,5);
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout <<array[i] <<" ";
    }

    system("pause");
}


void quicksort1(int array[],int left,int right)
{
    int i,j,temp,t;
    if (left >= right)
    {
        return ;
    }
    temp = array[left];
    i = left;
    j = right;
    while (i != j)
    {
        while (array[j] >= temp && j > i)               //从右边开始是为了保证与基准数交换的数小于基准数
        {
            j--;
        }
        // r = array[j];
        while (array[i] <= temp && j > i)
        {
            i++;
        }
        // l = array[i];
        if (j > i)
        {
            t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
        
    }
    array[left] = array[i];
    array[i] = temp;
    quicksort1(array,left,j-1);
    quicksort1(array,j+1,right);
}

void quicksort2(int array[],int left,int right)
{
    int i,j,temp,t;
    if (left >= right)
    {
        /* code */
        return ;
    }
    temp = array[left];
    i = left;
    j = right;

    // int l,r;
    while (i != j)
    {
        /* code */
        while (array[j] <= temp && j > i)
        {
            /* code */
            j--;
        }
        // r = array[j];
        while (array[i] >= temp && j > i)
        {
            /* code */
            i++;
        }
        // l = array[i];
        if (j > i)
        {
            /* code */
            t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
        
    }
   
    array[left] = array[i];
    array[i] = temp;
    
    
    quicksort2(array,left,j-1);
    quicksort2(array,j+1,right);
}