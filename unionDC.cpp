#include<iostream> //merging k sorted arrays into a single sorted array using divide and conquer paradigm
using namespace std;
struct listt
{
    int size;
    int arr[1000];
};
struct listt L[100];
struct listt merge(struct listt e,struct listt r);
struct listt mergesort(int ei,int ri);
int main()
{
    int N;
    cout<<"Enter the number of arrays:";
    cin>>N;
    cout<<"Enter the sizes of respective arrays:";
    for(int y=0;y<N;y++)
        cin>>L[y].size;
    for(int i=0;i<N;i++)
    {
        cout<<"Enter array "<<i+1<<":";
        for(int j=0;j<L[i].size;j++)
            cin>>L[i].arr[j];
    }
    struct listt R;
    R=mergesort(0,N-1);
    cout<<"Resultant array:";
    for(int i=0;i<R.size;i++)
        cout<<R.arr[i]<<" ";
    return 0;
}
struct listt merge(struct listt e,struct listt r)
{
    struct listt temp;
    temp.size=e.size+r.size;
    int i=0,j=0,k=0;
    while(i<e.size&&j<r.size)
    {
        if(e.arr[i]<r.arr[j])
        {
            temp.arr[k]=e.arr[i];
            i++;
        }
        else
        {
            temp.arr[k]=r.arr[j];
            j++;
        }
        k++;
    }
    while(i<e.size)
    {
        temp.arr[k]=e.arr[i];
        i++;
        k++;
    }
    while(j<r.size)
    {
        temp.arr[k]=r.arr[j];
        j++;
        k++;
    }
    return temp;
}
struct listt mergesort(int ei,int ri)
{
    if(ei==ri)
        return L[ei];
    else if(ri-ei==1)
        return merge(L[ei],L[ri]);
    else
    {
        int mid=(ri+ei)/2;
        return merge(mergesort(ei,mid),mergesort(mid+1,ri));
    }
}
