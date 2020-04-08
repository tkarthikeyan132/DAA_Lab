#include "Lab6.h"


stack<int> h[10000];

int bm(int b1,int b2)
{
    int q=b2;
    int r,tsum,sum=0,count=0;
    while(q!=0)
    {
        r=q%10;
        tsum=(r>0)?b1:0;
        sum=ba(tsum*pow(10,count),sum);
        count++;
        q/=10;
    }
    return sum;
}

int ba(int b1,int b2)
{
    int q1,r1,q2,r2,tsum=0,carry=0;
    int sum=0;
    int count=0;
    q1=b1;
    q2=b2;
    while(q1!=0||q2!=0)
    {
        r1=q1%10;
        r2=q2%10;
        tsum=(r1+r2+carry)%2;
        carry=(r1+r2+carry)/2;
        sum=tsum*pow(10,count)+sum;
        count++;
        q1/=10;
        q2/=10;
    }
    sum=carry*pow(10,count)+sum;
    return sum;
}

int dectobin(int n)
{
    int sum=0;
    int count=0;
    int q=n;
    int r;
    while(q!=0)
    {
        r=q%2;
        sum=pow(10,count)*r+sum;
        count++;
        q/=2;
    }
    return sum;
}
//_______________________________________________________________________________

void quicksort(int A[],int p,int r,int k)
{
    if(p<r)
    {
        int q=partition(A,p,r);
        if(k==0)
            return;
        else if(q-p>k)
            quicksort(A,p,q-1,k);
        else
            quicksort(A,q+1,r,k-(q-p+1));
    }
}
int partition(int A[],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i++;
            std::swap(A[i],A[j]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i+1;
}

//_______________________________________________________________________________

vector<int> minmaxpair(int *arr,int N) //to return min and max element in input array.
{
    int max,min;
    vector<int> v(2);
    if(N%2) //odd-sized array
    {   
        max=arr[0];
        min=arr[0];
        for(int i=1;i<N;i=i+2)
        {
            int maxt;
            int mint;
            if(arr[i]<arr[i+1])
            {
                mint=arr[i];
                maxt=arr[i+1];
            }
            else
            {
                mint=arr[i+1];
                maxt=arr[i];    
            }
            if(maxt>max)
                max=maxt;
            if(mint<min)
                min=mint;
        }   
    }
    else //even-sized array
    {
        if(arr[0]<arr[1])
        {
            min=arr[0];
            max=arr[1];
        }
        else
        {
            min=arr[1];
            max=arr[0];
        }
        for(int i=2;i<N;i=i+2)
        {
            int maxt;
            int mint;
            if(arr[i]<arr[i+1])
            {
                mint=arr[i];
                maxt=arr[i+1];
            }
            else
            {
                mint=arr[i+1];
                maxt=arr[i];    
            }
            if(maxt>max)
                max=maxt;
            if(mint<min)
                min=mint;
        }   
    }
    v[0] = min;
    v[1] = max;
    return v;
}


//_______________________________________________________________________________
bool divide1(int n,int d)  //n.logn
{
    if(n==0)
        return true;
    else if(n<0)
        return false;
    else
        return divide1(n-d,d);
}

//_______________________________________________________________________________
bool divide2(int n,int d)  //n.root(n)  //error
{
    string str="";
    for(int i=0;i<n;i++)
        str+='1';
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count==d-1)
            str[i]='$';
        count=(count+1)%d;
    }
    if(str[n-1]=='1')
        return false;
    else
        return true;
}

//__________________________________________________________________________

struct node tourna(struct node arr[],int n)
{
    if(n==1)
        return arr[0];
    int rn=(n%2)?n/2+1:n/2;
    struct node brr[rn];
    int k=0;
    for(int i=0;i<n-1;i=i+2)
    {
        if(arr[i].data>arr[i+1].data)
            brr[k]=arr[i];
        else
            brr[k]=arr[i+1];
        h[arr[i].index].push(arr[i+1].data);
        h[arr[i+1].index].push(arr[i].data);
        k++;
    }
    if(n%2)
        brr[k]=arr[n-1];
    tourna(brr,rn);
}

void showstack(stack <int> temp)
{
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
}

int findmax(stack <int> temp)
{
    int max=temp.top();
    temp.pop();
    while(!temp.empty())
    {
        if(temp.top()>max)
            max=temp.top();
        temp.pop();
    }
    return max;
}