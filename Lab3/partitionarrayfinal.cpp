#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int suml=0,sumr=0;
    int diff=0;
    cout<<"Enter the size of the array:";
    cin>>N;
    int arr[N];
    int M=N/2;
    int lrr[M];
    int rrr[M];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    for(int j=0;j<M;j++)
    {
        lrr[j]=arr[j];
        suml+=arr[j];
        rrr[j]=arr[M+j];
        sumr+=arr[M+j];
    }
    diff=sumr-suml;
    for(int i=0;i<M;i++)
    {
        for(int j=M-1;j>=0;j--)
        {
            if(lrr[j]<rrr[i])
            {
                int temp;
                temp=abs(diff-(2*(abs(lrr[j]-rrr[i]))));
                if(temp<diff)
                {
                    lrr[j]=lrr[j]^rrr[i];
                    rrr[i]=lrr[j]^rrr[i];
                    lrr[j]=lrr[j]^rrr[i];
                    diff=temp;
                }
            }
        }
    }
    cout<<"Left array:";
    for(int i=0;i<M;i++)
        cout<<lrr[i]<<" ";
    cout<<"Right array:";
    for(int i=0;i<M;i++)
        cout<<rrr[i]<<" ";
    cout<<endl;
    return 0;
}
