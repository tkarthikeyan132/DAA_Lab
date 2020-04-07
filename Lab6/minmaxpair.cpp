#include<iostream> //finding the minimum and maximum in an array in ((3n/2)-2) comparisons
#include<bits/stdc++.h>
using namespace std;
vector<int> minmaxpair(int *arr,int n);
int main()
{
    int N;
    cout<<"Enter the size of array:";
    cin>>N;
    int arr[N];
    cout<<"Enter the elements:";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    vector<int> r(2);
    r=minmaxpair(arr,N);
    cout<<"Maximum element:"<<r[0]<<endl;
    cout<<"Minimum element:"<<r[1]<<endl;
    return 0;
}
vector<int> minmaxpair(int *arr,int N)
{
    int max,min;
    vector<int> v;
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
    v.push_back(min);
    v.push_back(max);
    return v;
}
