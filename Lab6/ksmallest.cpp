#include<iostream> //Given an array of size n, finding k smallest elements
#include<bits/stdc++.h>
using namespace std;
void quicksort(int A[],int,int,int);
int partition(int A[],int p,int r);
int z;
int main()
{
    int N;
    cout<<"Enter the number of elements in array:";
    cin>>N;
    int A[N];
    cout<<"Enter the elements:";
    for(int k=0;k<N;k++)
        cin>>A[k];
    cout<<"How many smaller elements needed:";
    cin>>z;
    quicksort(A,0,N-1,z);
    cout<<"First k smallest elements:";
    for(int i=0;i<z;i++)
        cout<<A[i]<<" ";
    return 0;
}
void quicksort(int A[],int p,int r,int k)
{
    if(p<r)
    {
        int q=partition(A,p,r);
        if(k==0)
            return;
        else if(q-p>k)
            quicksort(A,p,q-1,k);
        else
            quicksort(A,q+1,r,k-(q-p+1));
    }
}
int partition(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            std::swap(A[i],A[j]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i+1;
}
    
    
