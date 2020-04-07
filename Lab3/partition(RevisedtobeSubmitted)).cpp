#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int n);
int main()
{
    int N,suml=0,sumr=0;
    int diff;
    cout << "Enter the size of the array( even ) : ";
    cin >> N;
    int arr[N];
    cout << "Enter the array : ";
    for(int i = 0;i < N; i++)
        cin >> arr[i];
    int lrr[N/2];
    int rrr[N/2];
    for(int i = 0; i < N/2; i++)
    {
        lrr[i]=arr[i];
        suml+=lrr[i];
        rrr[i]=arr[N/2+i];
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
    cout << "Left Array : ";
    printArray(lrr,N/2);
    cout << "Left sum : "<< suml;
    cout << "\nRight Array : ";
    printArray(rrr,N/2);
    cout << "Right sum : "<< sumr;
    return 0;
}
void printArray(int *arr,int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
