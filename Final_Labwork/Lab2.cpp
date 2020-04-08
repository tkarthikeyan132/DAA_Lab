#include "Lab2.h"

//int fibs[47]; // initialise fibs[0] and fibs[1], fibs[i] is i'th fibonacci number
int fibs[47]={0,1}; // initialise fibs[0] and fibs[1], fibs[i] is i'th fibonacci number

//Logic1
bool bruteforcesum(int arr[],int n,int sum)
{
    for(int i=0;i<n-1;i++)
    {
        int req=sum-arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==req)
                return true;
        }
    }
    return false;
}

//Logic2
bool leftrightsum(int arr[],int n,int sum)
{
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if((arr[l]+arr[r])==sum)
            return true;
        else if((arr[l]+arr[r])>sum)
            r--;
        else
            l++;
    }
    return false;
}

//Logic3
bool hashsum(int arr[],int n,int sum) 
{
    int maxi=*max_element(arr,arr+n);
    int mini=*min_element(arr,arr+n);
    int amaxi=max(maxi,abs(mini));
    int brr[100000]/*[(2*amaxi)+1]*/={0}; //brr[100000]={0}; it will solve but will create more space //brr[(2*maxi)+1]={0} it will result in  segmentation fault when number more than 2*maxi is searched
    for(int x=0;x<n;x++)  // for example amaxi=95 and sum=200 req=105 but for 105 no such space is created in hash table
    {
        if(arr[x]<0)
            brr[(2*arr[x]+1)*(-1)]=1;
        else
            brr[2*arr[x]]=1;
    }
    for(int y=0;y<n;y++)
    {
        int req=sum-arr[y];
        int reqm;
        if(req<0)
            reqm=((2*req)+1)*(-1);
        else
            reqm=2*req;
        if(brr[reqm]==1)
            return true;
    }
    return false;
}


//Logic4(a version of brute force)
bool binschsum(int arr[],int n,int sum)
{
    for(int z=0;z<n-1;z++)
    {
        int req=sum-arr[z];
        if(bs(arr,req,z+1,n-1))
            return true;
    }
    return false;
}

//helper for Logic4
bool bs(int arr[],int y,int beg,int end)
{
    if(beg>end)
        return false;
    int mid=(beg+end)/2;
    if(arr[mid]==y)
        return true;
    else if(arr[mid]<y)
        bs(arr,y,mid+1,end);
    else
        bs(arr,y,beg,mid-1);
}
//--------------------------------------------------------------------------------

int binminone(int arr[],int beg,int end)// finding first -1 in a very large size array whose size is not given, using binary search elements of the array should be non-decreasing until -1 is encountered.
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

//Logic1
int binmark(int arr[])  //exponential marking
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

//Logic2
int fibmark(int arr[])  //Fibonacci jumping marking
{
    int w=0;
    while(arr[fibs[w]]!=-1)
    {
        w++;
        if(w==21)
        {
            if(arr[9999]==-1)
                return -2;
            else
                w++;
        }
        if(w==22) // fib[21] is the first fibonacci number exceeding 10000
            return -1;
    }
    
    return w;
}

//Logic3
int linminone(int arr[]) // finding first -1 in a very large array whose size is not known using linear search
{
    for(int i=0;i<10000;i++)
    {
        if(arr[i]==-1)
            return i;
    }
    return -2;
}


//------------PATTERN PRINTING----------------------------------------------------

void pattern1(int w)
{
    for(int i=w;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
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
    cout<<endl;
}

void pattern3(int w)
{
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
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
    cout<<endl;
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
    cout << endl;
}
