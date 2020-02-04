#include<iostream> // finding first -1 in a very large sized aray whose array size is not given using fibonacci jump
using namespace std; // array should ne non-decreasing until -1 is encountered
int binminone(int arr[],int beg,int end);
int mark(int arr[]);
int fibs[47]={0,1}; // initialise fibs[0] and fibs[1], fibs[i] is i'th fibonacci number
int main()
{
    for(int i=2;i<47;i++) // fibonacci number generation
        fibs[i]=fibs[i-1]+fibs[i-2];
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
    int m=mark(A);
    if(m==-1)
        cout<<"-1 not found"<<endl;
    else
    {
        int y=binminone(A,fibs[m-1],fibs[m]);
        cout<<"first -1 is found at "<<y+1<<"th position"<<endl;
    }
    return 0;
}
int mark(int arr[])
{
    int w=0;
    while(arr[fibs[w]]!=-1)
    {
        w++;
        if(w==22) // fib[21] is the first fibonacci number exceeding 10000
            return -1;
    }
    
    return w;
}
int binminone(int arr[],int beg,int end)
{
    int mid=(beg+end)/2;
    if(beg==end)
        return end;
    if(arr[mid]==-1)
    {
        if(arr[mid-1]==-1)
            return binminone(arr,beg,mid-1);
        else
            return mid;
    }
    else
        return binminone(arr,mid+1,end);
}

    
