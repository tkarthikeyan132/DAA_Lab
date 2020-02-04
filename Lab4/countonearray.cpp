#include<iostream> // counting number of ones in a given array using divide and conquer
using namespace std;
int countone(int arr[],int l,int h);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<countone(A,0,n-1)<<endl;
    return 0;
}
int countone(int arr[],int l,int h)
{
    if(l==h)
        return arr[l];
    else if(h-l==1)
    {
        if(arr[l]==1)
        {
            if(arr[h]==1)
                return 2;
            else
                return 1;
        }
        else
        {
            if(arr[h]==1)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        int mid=(l+h)/2;
        return countone(arr,l,mid)+countone(arr,mid+1,h);
    }
}
    
