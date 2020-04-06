#include "Lab1.h"

using namespace std;

int gcd1_it(int m,int n)
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

int gcd1_rec(int m,int n,int d)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if((m%d==0)&&(n%d==0))
        return d;
    else
        return gcd1_rec(m,n,d-1);
}
//-------------------------------------------------------------------------------

int gcd2_it(int m,int n)
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

int gcd2_rec(int r1,int r2)
{
    if(r2==0)
        return r1;
    else
        return gcd2_rec(r2, r1%r2);
}
//-----------------------------------------------------------------------------

int gcd3_it(int m,int n)
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

int gcd3_rec(int m,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(m&1) //m is odd
    {
        if(n&1) //n is odd
            return gcd3_rec(abs(m-n)>>1,std::min(m,n));
        else //n is even
            return gcd3_rec(n>>1,m);
    }
    else //m is even
    {
        if(n&1) //n is odd
            return gcd3_rec(m>>1,n);
        else //n is even
            return gcd3_rec(m>>1,n>>1)<<1;
    }
}
 //---------------------------------------------------------------------------

int gcda_it(int b[],int k)
{
    if(k<=0)
        cout<<"Invalid number of inputs"<<endl;
    else if(k==1)
        return b[0];
    else
    {
        int temp=b[0];
        for(int i=1;i<k;i++)
            temp=gcd1_it(b[i],temp);
        return temp;
    }
}

int gcda_rec(int b[],int k)
{
    if(k<=0)
        cout<<"Invalid number of inputs"<<endl;
    else if(k==1)
        return abs(b[0]);
    else if(k==2)
        return gcd1_it(abs(b[0]),abs(b[1]));
    else
        return gcd1_it(abs(b[k-1]),gcda_rec(b,k-1));
}

//-------------------------------------------------------------------------------

