#include<iostream> // checking the presence of two numbers in an array whose sum is p using brute force method
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
bool bruteforcesum(int arr[],int n,int sum);
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
    if(bruteforcesum(A,n,s))
        cout<<"Yes possible"<<endl;
    else
        cout<<"Not possible"<<endl;
    end=clock();
    double duration=(double)(end-start)/(double)(1000000);
    cout<<fixed<<duration<<setprecision(6)<<endl;
    return 0;
}
bool bruteforcesum(int arr[],int n,int sum)
{
    for(int i=0;i<n-1;i++)
    {
        int req=sum-arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==req)
                return true;
        }
    }
    return false;
}
            
