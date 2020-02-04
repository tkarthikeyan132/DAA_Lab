#include<iostream> // finding first -1 in a very large array whose size is not known using linear search
using namespace std;
int linminone(int arr[]);
int main()
{
    int A[10000];
    for(int i=0;i<10000;i++)
        A[i]=-1;
    int i=0,x=0;
    while(x!=-1)
    {
        cin>>x;
        A[i]=x;
        i++;
    }
    int k=linminone(A);
    if(k!=-2)
        cout<<"first -1 is found at "<<k+1<<" position"<<endl;
    else
        cout<<"-1 not found"<<endl;
    return 0;
}
int linminone(int arr[])
{
    for(int i=0;i<10000;i++)
    {
        if(arr[i]==-1)
            return i;
    }
    return -2;
}
        
