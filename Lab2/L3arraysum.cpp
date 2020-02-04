#include<iostream> // checking the presence of two numbers in an array whose sum is p using hashing
#include<bits/stdc++.h>
using namespace std;
bool hashsum(int arr[],int n,int sum);
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
    if(hashsum(A,n,s))
        cout<<"Yes possible"<<endl;
    else
        cout<<"Not possible"<<endl;
    return 0;
}
bool hashsum(int arr[],int n,int sum) 
{
    int maxi=*max_element(arr,arr+n);
    int mini=*min_element(arr,arr+n);
    int amaxi=max(maxi,abs(mini));
    int brr[100000]/*[(2*amaxi)+1]*/={0}; //brr[100000]={0}; it will solve but will create more space //brr[(2*maxi)+1]={0} it will result in  segmentation fault when number more than 2*maxi is searched
    for(int x=0;x<n;x++)
    {
        if(arr[x]<0)
            brr[(2*arr[x]+1)*(-1)]=1;
        else
            brr[2*arr[x]]=1;
    }
    for(int y=0;y<n;y++)
    {
        int req=sum-arr[y];
        int reqm;
        if(req<0)
            reqm=((2*req)+1)*(-1);
        else
            reqm=2*req;
        if(brr[reqm]==1)
            return true;
    }
    return false;
}
            


    
