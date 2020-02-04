#include<iostream> // gcd using steins algorithm ( iterative implementation )
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
    int count=0;
    while(m!=n)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if((~m&1)&&(~n&1))
        {
            count++;
            m=m>>1;
            n=n>>1;
        }
        else if((~m&1)&&(n&1))
        {
            m=m>>1;
        }
        else if((m&1)&&(~n&1))
        {
            n=n>>1;
        }
        else
        {
            int temp=m;
            m=abs(m-n);
            n=std::min(temp,n);
        }
    }
    return m<<count;
}
    
    
