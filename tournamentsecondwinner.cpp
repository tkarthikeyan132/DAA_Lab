#include<iostream> //to find the second maximum(or minimum) in an array in (n+logn-2) comparisons
#include<bits/stdc++.h>
using namespace std;
struct node tourna(struct node arr[],int n);
struct node
{
    int data;
    int index;
};
void showstack(stack <int> temp);
int findmax(stack <int> temp);
stack <int> h[10000];
int main()
{
    int N;
    cout<<"Enter the number of elements in the array:";
    cin>>N;
    if(N==0)
    {
        cout<<"Terminated"<<endl;
        exit(0);
    }
    struct node arr[N];
    for(int i=0;i<N;i++)
        arr[i].index=i;
    cout<<"Enter the  elements:";
    for(int i=0;i<N;i++)
        cin>>arr[i].data;
    struct node res=tourna(arr,N);
    int secondmax;
    secondmax=findmax(h[res.index]);
    cout<<"Second maximum:"<<secondmax<<endl;
    return 0;
}
struct node tourna(struct node arr[],int n)
{
    if(n==1)
        return arr[0];
    int rn=(n%2)?n/2+1:n/2;
    struct node brr[rn];
    int k=0;
    for(int i=0;i<n-1;i=i+2)
    {
        if(arr[i].data>arr[i+1].data)
            brr[k]=arr[i];
        else
            brr[k]=arr[i+1];
        h[arr[i].index].push(arr[i+1].data);
        h[arr[i+1].index].push(arr[i].data);
        k++;
    }
    if(n%2)
        brr[k]=arr[n-1];
    tourna(brr,rn);
}
void showstack(stack <int> temp)
{
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
}
int findmax(stack <int> temp)
{
    int max=temp.top();
    temp.pop();
    while(!temp.empty())
    {
        if(temp.top()>max)
            max=temp.top();
        temp.pop();
    }
    return max;
}
