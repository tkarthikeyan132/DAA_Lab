#include"SORT_SEARCH.h"
using namespace std;
int main()
{
    int N;
    int swi;
    int x,res;
    cout << "Enter the size of the array: ";
    cin >> N;
    int arr[N];
    cout << "Enter the array elements: ";
    for(int y = 0; y < N; y++)
        cin >> arr[y];
    while(true)
    {
        cout << "\nOperations: \n1.Linear Search\n2.Binary Search\n3.Ternary Search\n4.Merge Sort\n5.Insertion Sort\n6.Selection Sort\n7.Exit\nEnter your choice: ";
        cin >> swi;
        switch(swi)
        {
            case 1: cout << "Enter the element to be searched: ";
                    cin >> x;
                    res = Linear_Search(arr,N,x);
                    if(res != -1)
                        cout << x <<" is found at "<<res+1<<" position" << endl;
                    else
                        cout << "Element not found !" << endl;
                    break;
                        
            case 2: cout << "Enter the element to be searched: ";
                    cin >> x;
                    res = Binary_Search(arr,N,0,N-1,x);
                    if(res != -1)
                        cout << x <<" is found at "<<res+1<<" position" << endl;
                    else
                        cout << "Element not found !" << endl;
                    break;
                
            case 3: cout << "Enter the element to be searched: ";
                    cin >> x;
                    res = Ternary_Search(arr,N,0,N-1,x);
                    if(res != -1)
                        cout << x <<" is found at "<<res+1<<" position" << endl;
                    else
                        cout << "Element not found !" << endl;
                    break;
                    
            case 4: Merge_Sort(arr,0,N-1);
                    cout << "Sorted array: ";
                    for(int i = 0; i < N; i++)
                        cout << arr[i] << " ";
                    cout << endl;
                    break;
                    
            case 5: Insertion_Sort(arr,N);
                    cout << "Sorted array: ";
                    for(int i = 0; i < N; i++)
                        cout << arr[i] << " ";
                    cout << endl;
                    break;
                
            case 6: Selection_Sort(arr,N);
                    cout << "Sorted array: ";
                    for(int i = 0; i < N; i++)
                        cout << arr[i] << " ";
                    cout << endl;
                    break;
            
            case 7: exit(0);
                
            default: cout << "Invalid operation !!" << endl;
        }
    }
    return 0;
}
