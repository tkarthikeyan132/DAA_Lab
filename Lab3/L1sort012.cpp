#include<iostream> // sorting 0,1,2 in the array using selection sort
#include<bits/stdc++.h>
using namespace std;
int linse(int arr[],int beg,int end,int x);
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    int k=0;
    while(linse(A,k,n,0)!=-1)
    {
        swap(A[k],A[linse(A,k,n,0)]);
        k++;
    }
    while(linse(A,k,n,1)!=-1)
    {
        swap(A[k],A[linse(A,k,n,1)]);
        k++;
    }
    while(linse(A,k,n,2)!=-1)
    {
        swap(A[k],A[linse(A,k,n,2)]);
        k++;
    }
    cout<<"New array:";
    for(int z=0;z<n;z++)
        cout<<A[z]<<" ";
    return 0;
}
int linse(int arr[],int beg,int end,int x)
{
    for(int i=beg;i<=end;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
