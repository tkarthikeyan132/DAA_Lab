#include<iostream> // gcd using brute force method ( recursive implementation )
using namespace std;
int gcd(int,int,int);
int main()
{
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    cout<<gcd(abs(a),abs(b),std::min(abs(a),abs(b)))<<endl;
    return 0;
}
int gcd(int m,int n,int d)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if((m%d==0)&&(n%d==0))
        return d;
    else
        return gcd(m,n,d-1);
}
