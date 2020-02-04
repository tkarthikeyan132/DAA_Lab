#include<iostream> // implementation of two way merge sort
#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[],int,int);
void merge(int lrr[],int,int rrr[],int,int acrr[]);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    mergesort(A,0,n-1);
    cout<<"Final array:";
    for(int k=0;k<n;k++)
        cout<<A[k]<<" ";
    return 0;
}
void mergesort(int arr[],int beg,int end)
{
    if(beg==end)
        return;
    else
    {
        int mid=(beg+end)/2;
        int n1=mid-beg+1; //size of larray
        int n2=end-mid; //size of rarray
        int L[n1];
        int R[n2];
        for(int i=0;i<n1;i++)
            L[i]=arr[beg+i];
        for(int j=0;j<n2;j++)
            R[j]=arr[mid+1+j];
        mergesort(L,0,n1-1);
        mergesort(R,0,n2-1);
        merge(L,n1,R,n2,arr);
    }
}
void merge(int lrr[],int lsize,int rrr[],int rsize,int acrr[])
{
    int i=0,j=0,k=0;
    while(i<lsize&&j<rsize)
    {
        if(lrr[i]<rrr[j])
        {
            acrr[k]=lrr[i];
            i++;
        }
        else
        {
            acrr[k]=rrr[j];
            j++;
        }
        k++;
    }
    while(i<lsize)
    {
        acrr[k]=lrr[i];
        i++;
        k++;
    }
    while(j<rsize)
    {
        acrr[k]=rrr[j];
        j++;
        k++;
    }
}
    
