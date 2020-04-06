#include<iostream>
#include"BASIC.h"
using namespace std;

int Addition(int a,int b)
{
    int t;
    t = a+b;
    return t;
}
int Subtraction(int a,int b)
{
    int t;
    t = a-b;
    return t;
}
int Multiplication(int a,int b)
{
    int t;
    t = a*b;
    return t;
}
int Division(int a,int b)
{
    if(b==0)
    {
        cout << "Not defined" <<endl;
        return NFDBITS;
    }
    int t;
    t=a/b;
    return t;
}

int fact(int f)
{
    if(f==1||f==0)
        return 1;
    else
        return (f * fact(f-1));
}

double power(float x, int n)
{
    if(n == 0)
        return 1;
    else if(n > 0)
        return (x * power(x, n - 1));
    else
        return (1 / power(x, n));
}
    
