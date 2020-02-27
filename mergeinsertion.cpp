#include<iostream> //array of size 10^5 is sorted using divide and conquer and applying insertion sort when array size is reduced to 10^3 
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
void mergesort(int* arr,int,int);
void merge(int* lrr,int,int* rrr,int,int* acrr);
void inssort(int *arr,int beg,int end) //Insertion Sort
{
    int key,i;
    for(int j=beg+1;j<=end;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0&&arr[i]>key) 
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}
int main()
{
    int arr[100000]={0};
    srand((unsigned)time(0));
    for(int i=0;i<100000;i++) //generating random array
        arr[i]=(rand()%100)*pow(10,rand()%3)*pow(-1,rand()%2);
    mergesort(arr,0,99999);
    cout<<"Sorted array:";
    for(int i=0;i<100000;i++)
        cout<<arr[i]<<" ";
    return 0;
}
void mergesort(int* arr,int beg,int end)
{
    if((end-beg)<=999)
    {
        inssort(arr,beg,end);
    }
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
void merge(int* lrr,int lsize,int* rrr,int rsize,int* acrr)
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
    
