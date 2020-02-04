#include<iostream> // checking the presence of two numbers in an array whose sum is p using left right pointer method
#include<time.h> // sorted array should be ensured, then left pointer is incremented or right pointer is decremented based on the comparison
#include<bits/stdc++.h> //merge sort used instead of sort function
using namespace std;
bool leftrightsum(int arr[],int n,int sum);
void mergesort(int arr[],int n);
void merge(int lr[],int l,int rr[],int r,int arr[],int n);
int main()
{
    int n,s;
    cout<<"Enter the size of array:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the value of sum:";
    cin>>s;
    clock_t start,end;
    start=clock();
    mergesort(A,n); 
    if(leftrightsum(A,n,s))
        cout<<"Yes possible"<<endl;
    else
        cout<<"Not possible"<<endl;
    end=clock();
    double dur=(double)(end-start)/(double)(1000000);
    cout<<"Exec time:"<<fixed<<dur<<setprecision(6)<<endl;
    return 0;
}
bool leftrightsum(int arr[],int n,int sum)
{
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if((arr[l]+arr[r])==sum)
            return true;
        else if((arr[l]+arr[r])>sum)
            r--;
        else
            l++;
    }
    return false;
}
void mergesort(int arr[],int n)
{
    if(n==1)
        return;
    int mid=(n)/2;
    int nl=mid; //size of left array
    int nr=(n)-mid; //size of right array
    int L[nl];
    int R[nl];
    int k=0;
    for(int i=0;i<nl;i++)
        L[i]=arr[i];
    for(int j=0;j<nr;j++)
        R[j]=arr[mid+j];
    mergesort(L,nl);
    mergesort(R,nr);
    merge(L,nl,R,nr,arr,n);
}    
void merge(int lr[],int l,int rr[],int r,int arr[],int n)
{
    int i=0,j=0,k=0;
    int nl=l;
    int nr=r;
    while(i<nl&&j<nr)
    {
        if(lr[i]<=rr[j])
        {
            arr[k]=lr[i];
            i++;
        }
        else
        {
            arr[k]=rr[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        arr[k]=lr[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k]=rr[j];
        j++;
        k++;
    }
}
