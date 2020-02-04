#include<iostream>
using namespace std;
int gcd(int,int);
int gcda(int a[],int);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int a[n];
    cout<<"Enter the n entries:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<gcda(a,n)<<endl;
    return 0;
}
int gcd(int r1,int r2)
{
    if(r2==0)
        return r1;
    else
        return gcd(r2,r1%r2);
}
int gcda(int b[],int k)
{
    if(k<=0)
        cout<<"Invalid number of inputs"<<endl;
    else if(k==1)
        return abs(b[0]);
    else if(k==2)
        return gcd(abs(b[0]),abs(b[1]));
    else
        return gcd(abs(b[k-1]),gcda(b,k-1));
}
    
