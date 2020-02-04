#include<iostream> // printing 5 patterns whose size would depend on the value of n
using namespace std;
void pattern1(int);
void pattern2(int);
void pattern3(int);
void pattern4(int);
void pattern5(int);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    pattern1(n);
    cout<<endl;
    pattern2(n);
    cout<<endl;
    pattern3(n);
    cout<<endl;
    pattern4(n);
    cout<<endl;
    pattern5(n);
    cout<<endl;
    return 0;
}
void pattern1(int w)
{
    for(int i=w;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
}
void pattern2(int w)
{
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=i-1;j++)
            cout<<"  ";
        for(int k=i;k<=w;k++)
            cout<<k<<" ";
        cout<<endl;
    }
}
void pattern3(int w)
{
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
}
void pattern4(int w)
{
    for(int i=w;i>=1;i--)
    {
        for(int j=1;j<=i-1;j++)
            cout<<"  ";
        for(int k=i;k<=w;k++)
            cout<<k<<" ";
        cout<<endl;
    }
}
void pattern5(int w)
{
    for(int j=1;j<=w/2;j++)
    {
        for(int s=1;s<=(j-1);s++)
            cout<<"  ";
        for(int k=j;k<=w-j+1;k++)
            cout<<k<<" ";
        for(int s=1;s<=(j-1);s++)
            cout<<"  ";
        cout<<endl;
    }
    if(w%2)
    {
        for(int i=1;i<=w/2;i++)
            cout<<"  ";
        cout<<w/2+1<<endl;
    }
    for(int j=w/2;j>=1;j--)
    {
        for(int s=1;s<=j-1;s++)
            cout<<"  ";
        for(int k=j;k<=w-j+1;k++)
            cout<<k<<" ";
        for(int s=1;s<=j-1;s++)
            cout<<"  ";
        cout<<endl;
    }
}
            
        
