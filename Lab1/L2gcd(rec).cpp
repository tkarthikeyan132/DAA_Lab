#include<iostream> // gcd using euclids algorithm ( recursive implementation )
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
int gcd(int r1,int r2)
{
    if(r2==0)
        return r1;
    else
        return gcd(r2,r1%r2);
}
