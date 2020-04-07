
#include<iostream> //merging k sorted arrays into a single sorted array using merge subroutine of merge sort(that is using k pointers)
using namespace std;
struct megalist union_of_array(struct listt L[],int N);
struct listt
{
    int arr[100];
    int ptr;
    int size;
};
struct megalist
{
    int arr[1000];
    int ptr;
    int size;
};
int main()
{
    int N;
    cout<<"Enter the number of arrays:";
    cin>>N;
    struct listt L[N];
    struct megalist M;
    M = union_of_array(L,N);
    cout<<"Sorted array:";
    for(int z=0;z<M.size;z++)
        cout<<M.arr[z]<<" ";
    return 0;
}
struct megalist union_of_array(struct listt L[],int N)
{
    int flag=1;
    int maxi; //positive infinity
    struct megalist M;
    M.ptr=0;
    M.size=0;
    cout<<"Enter the size of respective arrays:";
    for(int i=0;i<N;i++)
        cin>>L[i].size;
    for(int x=0;x<N;x++)
    {
        cout<<"Enter array "<<x+1<<":";
        L[x].ptr=0;
        for(int y=0;y<L[x].size;y++)
            cin>>L[x].arr[y];
    }
    maxi=L[0].arr[0];
    for(int x=0;x<N;x++)
        for(int y=0;y<L[x].size;y++)
            if(L[x].arr[y]>maxi)
                maxi=L[x].arr[y];
    maxi++;
    while(flag)
    {
        flag=0;
        int mini=maxi;
        int indmin=-1;
        for(int k=0;k<N;k++)
        {
            if(L[k].ptr<L[k].size)
            {
                if(L[k].arr[L[k].ptr]<mini)
                {
                    mini=L[k].arr[L[k].ptr];
                    indmin=k;
                }
            }
        }
        L[indmin].ptr++;
        M.arr[M.ptr]=mini;
        M.ptr++;
        M.size++;
        for(int i=0;i<N;i++)
        {
            if(L[i].ptr<L[i].size)
                flag++;
        }
    }
    return M;
}
    
