#include<iostream> // finding first -1 in a very large size array whose size is not given using binary search
using namespace std; // elements of the array should be non-decreasing until -1 is encountered
int binminone(int arr[],int beg,int end);
int mark(int arr[]);
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
    int m=mark(A);
    if(m==-1)
        cout<<"-1 not found"<<endl;
    int k=binminone(A,m/2,m);
    cout<<"first -1 is found at "<<k+1<<" position"<<endl;
    return 0;
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
int mark(int arr[])
{
    if(arr[0]==-1)
        return 0;
    else
    {
        int i=1;
        while(arr[i]!=-1)
        {
            i*=2;
            if(i>10000) // when index exceeds the size of array
                return -1;
        }
        return i;
    }
}
