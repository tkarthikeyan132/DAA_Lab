#include<iostream> // tower of hanoi implementation showing tranfer of discs
using namespace std;
void tower(int,char,char,char);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    tower(n,'A','B','C');
    return 0;
}
void tower(int a,char from,char aux,char to)
{
    if(a==1)
        cout<<"Move disc "<<a<<" from "<<from<<" to "<<to<<endl;
    else
    {
        tower(a-1,from,to,aux);
        cout<<"Move disc "<<a<<" from "<<from<<" to "<<to<<endl;
        tower(a-1,aux,from,to);
    }
}
