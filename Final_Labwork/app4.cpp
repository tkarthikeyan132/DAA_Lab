#include "Lab4.h"
int main()
{
    int size, n;
    cout << "Enter the array size to calculate GCD: ";
    cin >> size;
    int A[size];
    cout << "Enter the array of integers: ";
    for(int i = 0; i < size; i++)
        cin >> A[i];
    cout << "Enter 1 to print GCD (using D&C) of these integers:\nEnter 2 to print no. of 1's :\nEnter 3 to print no. of negative numbers.\nEnter 4 to do two way merge-sort.\nEnter 5 to do three-way merge-sort.\n ";
    switch (n)
    {
        case 1:
            cout << "GCD: "<< gcda(A,0,size-1) << endl;
            break;

        case 2:
            cout << "No. of 1's: "<< countone(A,0,size-1) << endl;
            break;

        case 3:
            cout << "No. of negative numbers: "<< countneg(A,0,size-1) << endl;
            break;

        case 4:
            twowaymergesort(A,0,n-1);
            cout << "Final array after two-way mergesort:" << endl;
            for(int k=0;k<n;k++)
                cout<<A[k]<<" ";
            break;

        case 5:
            threewaymergesort(A,0,n-1);
            cout << "Final array after three-way mergesort:" << endl;
            for(int k=0;k<n;k++)
                cout<<A[k]<<" ";
            break;
    
        default:
            cout << "INVALID INPUT, try again.\n";
            break;
    } 

    cout << "Enter the no of discs to implement towers of hanoi: ";
    cin >> size;
    tower(size, 'A', 'B', 'C');
    return 0;
}
