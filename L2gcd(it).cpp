#include<iostream> // gcd using euclids algorithm ( iterative implementation )
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
    if(m==0)
        return n;
    if(n==0)
        return m;
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
        
    
