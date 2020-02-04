#include<iostream> // gcd for k numbers ( iterative implementation )
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
int gcd(int m,int n)
{
    int x=m;
    int y=n;
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int gcda(int b[],int k)
{
    if(k<=0)
        cout<<"Invalid number of inputs"<<endl;
    else if(k==1)
        return b[0];
    else
    {
        int temp=b[0];
        for(int i=1;i<k;i++)
            temp=gcd(b[i],temp);
        return temp;
    }
}
