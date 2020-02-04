#include<iostream> // lcm of numbers in a array using divide and conquer
using namespace std;
int gcd(int,int);
long lcm(int,int);
int lcma(int arr[],int l,int h);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<lcma(A,0,n-1)<<endl;
    return 0;
}
int gcd(int m,int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
long lcm(int m,int n)
{
    if(m==0||n==0)
    {
        cout<<"not defined"<<endl;
        exit(0);
    }
    else
    {
        int g=gcd(m,n);
        int mul=m*n;
        int res=mul/g;
        return res;
    }
}
int lcma(int arr[],int l,int h)
{
    if(l==h)
        return abs(arr[l]);
    else if(h-l==1)
        return lcm(abs(arr[l]),abs(arr[h]));
    else
    {
        int mid=(l+h)/2;
        return lcm(lcma(arr,l,mid),lcma(arr,mid+1,h));
    }
}
