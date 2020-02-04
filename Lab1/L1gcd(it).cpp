#include<iostream> // gcd using brute force method ( iterative implementation )
using namespace std;
int gcd(int,int);
int main()
{
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    cout<<gcd(abs(a),abs(b))<<endl;
    return 0;
}
int gcd(int m,int n)
{
    int t=std::min(m,n);
    if(m==0)
        return n;
    if(n==0)
        return m;
    while(t>0)
    {
        if((m%t==0)&&(n%t==0))
            return t;
        t--;
    }
}
        
