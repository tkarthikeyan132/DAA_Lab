#include<iostream> // counting number of negative numbers in a given array using divide and conquer
using namespace std;
int countneg(int arr[],int l,int h);
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int A[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<countneg(A,0,n-1)<<endl;
    return 0;
}
int countneg(int arr[],int l,int h)
{
    if(l==h)
    {
        if(arr[l]<0)
            return 1;
        else
            return 0;
    }
    else if(h-l==1)
    {
        if(arr[l]<0)
        {
            if(arr[h]<0)
                return 2;
            else
                return 1;
        }
        else
        {
            if(arr[h]<0)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        int mid=(l+h)/2;
        return countneg(arr,l,mid)+countneg(arr,mid+1,h);
    }
}
    
