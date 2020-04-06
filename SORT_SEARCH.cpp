#include"SORT_SEARCH.h"
int Linear_Search(int arr[],int n,int x)
{
    for(int i = 0;i < n;i++)
        if(arr[i] == x)
            return i;
    return -1;
}
int Binary_Search(int arr[],int n,int beg,int end,int x)
{
    if(beg > end)
        return -1;
    int mid = (beg + end) / 2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] < x)
        return Binary_Search(arr,n,mid+1,end,x);
    else
        return Binary_Search(arr,n,beg,mid-1,x);
}
int Ternary_Search(int arr[],int n,int beg,int end,int x)
{
    if(beg > end)
        return -1;
    int mid1 = beg + (end - beg) / 3;
    int mid2 = end - (end - beg) / 3;
    if(arr[mid1] == x)
        return mid1;
    else if(arr[mid2] == x)
        return mid2;
    else if(x < arr[mid1])
        return Ternary_Search(arr,n,beg,mid1-1,x);
    else if(x < arr[mid2])
        return Ternary_Search(arr,n,mid1+1,mid2-1,x);
    else
        return Ternary_Search(arr,n,mid2+1,end,x);
} 
void Merge_Sort(int *arr,int from,int to)
{
    int mid;
    if(from < to)
    {
        mid = (from + to) / 2;
        Merge_Sort(arr,from,mid);
        Merge_Sort(arr,mid+1,to);
        Merge(arr,from,mid,to);
    }
} 
void Merge(int *arr,int from,int mid,int to)
{
    int i = from;
    int j = mid+1;
    int k = 0;
    int temp[to-from+1];
    while(i <= mid && j <= to)
    {
        if(*(arr+i) < *(arr+j))
        {
            temp[k] = *(arr+i);
            k++; i++;
        }
        else
        {
            temp[k] = *(arr+j);
            k++; j++;
        }
    }
    while(i <= mid)
    {
        temp[k] = *(arr+i);
        k++; i++;
    }
    while(j <= to)
    {
        temp[k] = *(arr+j);
        k++; j++;
    }
    for(int i = from; i<=to; i++)
        *(arr+i) = temp[i-from];
}
void Insertion_Sort(int *arr,int n)
{
    for(int j = 1; j < n; j++)
    {
        int key = *(arr+j);
        int i = j-1;
        while( i>0 && *(arr+i)>key)
        {
            *(arr+i+1) = *(arr+i);
            i = i-1;
        }
        *(arr+i+1) = key;
    }
}
void Selection_Sort(int *arr,int n)
{
    int min;
    for(int i = 0; i < n-1 ; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(*(arr+j) < *(arr+i))
                min = j;
        }
        std::swap(*(arr+i),*(arr+min));
    }
}
