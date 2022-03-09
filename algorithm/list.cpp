#include<iostream>

using namespace std;

struct node
{
    /* data */
    int data;
    struct node *next;
    
};


int main()
{
    struct node *head,*p,*q,*t;
    head = new(struct node);
    int i,n,data;
    cout <<"需要存入的数据：";
    cin >>n;
    head->next = NULL;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        cin >> data;
        p = new(struct node);
        p->data = data;
        p->next = NULL;
        if (head->next == NULL)
        {
            /* code */
            head->next = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    cout <<"请输入需要插入的数据：";
    cin >>data;
    t = head;
    while (true)
    {
        /* code */
        if(t->next == NULL || t->next->data >= data)
        {
            p = new(struct node);
            p->data = data;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
    
    t = head->next;
    while (t != NULL)
    {
        /* code */
        cout <<t->data <<"  ";
        t = t->next;
    }
    
}