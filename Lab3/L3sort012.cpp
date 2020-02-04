#include<iostream> // sorting 0,1,2 in the array using hashing
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
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
    cout<<"New array:";   
    for(int z=0;z<n;z++)
        cout<<A[z]<<" ";
    return 0;
}
