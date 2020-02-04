#include<iostream> //checking the presence of two numbers in an array whose sum is p using brute force with some variation
#include<bits/stdc++.h> // sorted array is ensured and then binary search is applied
#include<time.h>
using namespace std;
bool binschsum(int arr[],int n,int sum);
bool bs(int arr[],int y,int beg,int end);
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
    sort(A,A+n);
    if(binschsum(A,n,s))
        cout<<"Yes possible"<<endl;
    else
        cout<<"Not possible"<<endl;
    end=clock();
    double duration=(double)(end-start)/(double)(1000000);
    cout<<"Exec time:"<<fixed<<duration<<setprecision(6)<<endl;
    return 0;
}
bool binschsum(int arr[],int n,int sum)
{
    for(int z=0;z<n-1;z++)
    {
        int req=sum-arr[z];
        if(bs(arr,req,z+1,n-1))
            return true;
    }
    return false;
}
bool bs(int arr[],int y,int beg,int end)
{
    if(beg>end)
        return false;
    int mid=(beg+end)/2;
    if(arr[mid]==y)
        return true;
    else if(arr[mid]<y)
        bs(arr,y,mid+1,end);
    else
        bs(arr,y,beg,mid-1);
}
    
