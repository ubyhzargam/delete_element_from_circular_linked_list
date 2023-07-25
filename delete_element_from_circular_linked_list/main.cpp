//
//  main.cpp
//  delete_element_from_circular_linked_list
//
//  Created by Uby H on 25/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
void create(int n, int A[])
{
    struct Node *t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=head;
        last->next=t;
        last=t;
    }
}
void display(int n)
{
    struct Node *p=head;
    for(int i=0;i<n;i++)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Del(int pos,int n)
{
    int x;
    if(pos<1||pos>n)
        return -1;
    struct Node *q,*p;
    p=head;
    if(pos==1)
    {
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
            p=p->next;
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
    }
    return x;
}
int main()
{
    int x=0,n,pos;
    cout<<"Enter the number of elements in the circular linked list : "<<endl;
    cin>>n;
    cout<<"Enter the elements in the linked list : "<<endl;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    create(n,A);
    cout<<"The original linked list is given by : "<<endl;
    display(n);
    cout<<"Enter the position at which the element should be deleted : "<<endl;
    cin>>pos;
    x=Del(pos,x);
    if(x<0)
        cout<<"The given index is invalid "<<endl;
    else{
        cout<<"The element "<<x<<" was deleted from the linked list and the updated linked list is given by : "<<endl;
        display(n-1);}
    return 0;
}
