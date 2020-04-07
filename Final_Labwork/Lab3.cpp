#include"Lab3.h"
using namespace std;
void partition(int *arr,int *lrr,int *rrr,int N)
{
    int suml=0,sumr=0;
    int diff;
    for(int i = 0; i < N/2; i++)
    {
        suml+=lrr[i];
        sumr+=rrr[i];
    }
    int tsuml = suml;
    int tsumr = sumr;
    diff = abs(sumr - suml);
    int tdiff = abs(tsumr - tsuml);
    for(int i = 0; i < N/2; i++)
    {
        for(int j = N/2-1; j >= 0; j--)
        {
            tsuml = suml - lrr[j] + rrr[i];
            tsumr = sumr - rrr[i] + lrr[j];
            tdiff = abs(tsumr - tsuml);
            if(tdiff < diff)
            {
                int tv = *(lrr + j);
                *(lrr + j) = *(rrr + i);
                *(rrr + i) = tv;
                diff = tdiff;
                suml = tsuml;
                sumr = tsumr;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------
int linse(int arr[],int beg,int end,int x)
{
    for(int i=beg;i<=end;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
void L1sort012(int *A,int n)
{
    int k=0;
    while(linse(A,k,n,0)!=-1)
    {
        swap(A[k],A[linse(A,k,n,0)]);
        k++;
    }
    while(linse(A,k,n,1)!=-1)
    {
        swap(A[k],A[linse(A,k,n,1)]);
        k++;
    }
    while(linse(A,k,n,2)!=-1)
    {
        swap(A[k],A[linse(A,k,n,2)]);
        k++;
    }
}
//-------------------------------------------------------------------------------------------------------
void L2sort012(int *A,int n)
{
    queue<int> q[3];
    for(int k=0;k<n;k++)
    {
        if(A[k]==0)
        {
            q[0].push(A[k]);
        }
        else if(A[k]==1)
        {
            q[1].push(A[k]);
        }
        else if(A[k]==2)
        {
            q[2].push(A[k]);
        }
    }
    int p=0;
    while(!q[0].empty())
    {
        A[p++]=q[0].front();
        q[0].pop();
    }
    while(!q[1].empty())
    {
        A[p++]=q[1].front();
        q[1].pop();
    }
    while(!q[2].empty())
    {
        A[p++]=q[2].front();
        q[2].pop();
    }
}
//-----------------------------------------------------------------------------------------------------
void L3sort012(int *A,int n)
{
    int y=3*n;
    int B[y]={0};
    for(int k=0;k<n;k++)
        B[3*k+(A[k])]=1;
    int r=0;
    for(int e=0;e<y;e=e+3) //0
    {
        if(B[e]==1)
            A[r++]=e%3;
    }
    for(int e=1;e<y;e=e+3) //1
    {
        if(B[e]==1)
            A[r++]=e%3;
    }
    for(int e=2;e<y;e=e+3) //2
    {
        if(B[e]==1)
            A[r++]=e%3;
    }
}
//------------------------------------------------------------------------------------------------------
void printArray(int *A,int n)
{
    cout<<"New array:";
    for(int z=0;z<n;z++)
        cout<<A[z]<<" ";
}
