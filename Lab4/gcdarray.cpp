#include<iostream> // gcd of numbers in a array using divide and conquer
using namespace std;
int gcd(int,int);
int gcda(int arr[],int l,int h);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<gcda(A,0,n-1)<<endl;
    return 0;
}
int gcd(int m,int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
int gcda(int arr[],int l,int h)
{
    if(l==h)
        return abs(arr[l]);
    else if(h-l==1)
        return gcd(abs(arr[l]),abs(arr[h]));
    else
    {
        int mid=(l+h)/2;
        return gcd(gcda(arr,l,mid),gcda(arr,mid+1,h));
    }
}
