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
int Factorial(int f)
{
    if(f==1||f==0)
        return 1;
    else
        return f*Factorial(f-1);
}
int Power(int a,int b)
{
    if(b==0)
        return 1;
    else
        return a*Power(a,b-1);
}
    
