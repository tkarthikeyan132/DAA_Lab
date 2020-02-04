#include<iostream>
#include<cmath>
using namespace std;
int gcd(int,int);
int main()
{
    int a,b;
    cout<<"Enter two number:";
    cin>>a>>b;
    cout<<gcd(abs(a),abs(b))<<endl;
    return 0;
}
int gcd(int m,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(m&1) //m is odd
    {
        if(n&1) //n is odd
            return gcd(abs(m-n)>>1,std::min(m,n));
        else //n is even
            return gcd(n>>1,m);
    }
    else //m is even
    {
        if(n&1) //n is odd
            return gcd(m>>1,n);
        else //n is even
            return gcd(m>>1,n>>1)<<1;
    }
}
        
