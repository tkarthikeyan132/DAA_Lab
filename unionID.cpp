#include<iostream> //merging k sorted arrays into a single sorted array using incremental design
#include<bits/stdc++.h>
using namespace std;
struct listt
{
    int A[100];
    int ptr;
    int size;
};
struct megalist
{
    int M[10000];
    int ptr;
    int size;
};
struct megalist merge(struct listt temp,struct megalist m);
int main()
{
    int t,N=0; //number of arrays
    cout<<"Enter the number of array:";
    cin>>N;
    struct listt B[N];
    struct megalist T;
    cout<<"Enter the size of respective arrays:";
    for(int i=0;i<N;i++)
    {
        cin>>t;
        B[i].size=t;
        B[i].ptr=0;
    }
    for(int j=0;j<N;j++)
    {
        cout<<"Enter the elements of array "<<j+1<<":";
        for(int k=0;k<B[j].size;k++)
        {
            cin>>B[j].A[k];
        }
    }
    T.size=B[0].size;
    for(int k=0;k<T.size;k++)
        T.M[k]=B[0].A[k];
    for(int u=1;u<N;u++)
        T=merge(B[u],T);
    cout<<"Sorted array:";
    for(int k=0;k<T.size;k++)
        cout<<T.M[k]<<" ";
    return  0;
}
struct megalist merge(struct listt t,struct megalist m)
{
    struct megalist temp;
    int x=t.size;
    int y=m.size;
    temp.size=0;
    int i=0,j=0,k=0;
    while(i<x&&j<y)
    {
        if(t.A[i]<m.M[j])
        {
            temp.M[k]=t.A[i];
            i++;
        }
        else
        {
            temp.M[k]=m.M[j];
            j++;
        }
        k++;
    }
    while(i<x)
    {
        temp.M[k]=t.A[i];
        i++;
        k++;
    }
    while(j<y)
    {
        temp.M[k]=m.M[j];
        j++;
        k++;
    }
    temp.size=k;
    return temp;
}
