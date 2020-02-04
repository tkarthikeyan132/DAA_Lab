#include<iostream> // implementation of three way merge sort
#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[],int,int);
void merge(int frr[],int,int srr[],int,int trr[],int,int acrr[]);
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
    else if(end-beg==1)
    {
        if(arr[beg]>arr[end])
        {
            arr[beg]=arr[beg]^arr[end];
            arr[end]=arr[beg]^arr[end];
            arr[beg]=arr[beg]^arr[end];
        }
        return;
    }
    else
    {
        int mid1=(end-beg)/3;
        int mid2=2*(end-beg)/3;
        int nf=mid1-beg+1; //size of first array
        int ns=mid2-mid1; //size of second array
        int nt=end-mid2; //size of third array
        int F[nf];
        int S[ns];
        int T[nt];
        for(int i=0;i<nf;i++)
            F[i]=arr[beg+i];
        for(int j=0;j<ns;j++)
            S[j]=arr[mid1+1+j];
        for(int k=0;k<nt;k++)
            T[k]=arr[mid2+1+k];
        mergesort(F,0,nf-1);
        mergesort(S,0,ns-1);
        mergesort(T,0,nt-1);
        merge(F,nf,S,ns,T,nt,arr);
    }
}
void merge(int frr[],int fs,int srr[],int ss,int trr[],int ts,int acrr[])
{
    int i=0,j=0,k=0,w=0;
    while(i<fs&&j<ss&&k<ts)
    {
        int flag=0;
        int tem=frr[i];
        if(srr[j]<tem)
        {
            flag=1;
            tem=srr[j];
        }
        if(trr[k]<tem)
        {
            flag=2;
            tem=trr[k];
        }
        acrr[w]=tem;
        if(flag==0)
            i++;
        else if(flag==1)
            j++;
        else
            k++;
        w++;
    }
    while(i<fs&&j<ss)
    {
        if(frr[i]<srr[j])
        {
            acrr[w]=frr[i];
            i++;
        }
        else
        {
            acrr[w]=srr[j];
            j++;
        }
        w++;
    }
    while(i<fs&&k<ts)
    {
        if(frr[i]<trr[k])
        {
            acrr[w]=frr[i];
            i++;
        }
        else
        {
            acrr[w]=trr[k];
            k++;
        }
        w++;
    }
    while(j<ss&&k<ts)
    {
        if(srr[j]<trr[k])
        {
            acrr[w]=srr[j];
            j++;
        }
        else
        {
            acrr[w]=trr[k];
            k++;
        }
        w++;
    }
    while(i<fs)
    {
        acrr[w]=frr[i];
        i++;
        w++;
    }
    while(j<ss)
    {
        acrr[w]=srr[j];
        j++;
        w++;
    }
    while(k<ts)
    {
        acrr[w]=trr[k];
        k++;
        w++;
    }
}
