#include<iostream> // sorting 0,1,2 in the array using queue data structure
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node* enqueue(int x,struct node *r);
struct node* dequeue(struct node *f);
struct node* f0=NULL;
struct node* r0=NULL;
struct node* f1=NULL;
struct node* r1=NULL;
struct node* f2=NULL;
struct node* r2=NULL;
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int k=0;k<n;k++)
    {
        if(A[k]==0)
        {
            r0=enqueue(A[k],r0);
            if(f0==NULL)
                f0=r0;
        }
        else if(A[k]==1)
        {
            r1=enqueue(A[k],r1);
            if(f1==NULL)
                f1=r1;
        }
        else if(A[k]==2)
        {
            r2=enqueue(A[k],r2);
            if(f2==NULL)
                f2=r2;
        }
    }
    int p=0;
    while(f0!=NULL)
    {
        A[p++]=f0->data;
        f0=dequeue(f0);
    }
    while(f1!=NULL)
    {
        A[p++]=f1->data;
        f1=dequeue(f1);
    }
    while(f2!=NULL)
    {
        A[p++]=f2->data;
        f2=dequeue(f2);
    }
    cout<<"New array:";
    for(int y=0;y<n;y++)
        cout<<A[y]<<" ";
    return 0;
}
struct node* enqueue(int x,struct node *r)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node *));
    temp->data=x;
    temp->next=NULL;
    if(r==NULL)
    {
        r=temp;
        return r;
    }
    r->next=temp;
    r=temp;
    return r;
}
struct node* dequeue(struct node *f)
{
    f=f->next;
    return f;
}
