#include "Lab5.h"
#include "Lab4.h"

int main()
{
    int p, k = 0;
    cout << "Enter the problem no 1 or 2: ";
    cin >> p;
    cout << "Enter the no. of arrays: ";
    cin >> k;
    Unit Unit_Array[k];
    vector<int> Sorted_Array;
    struct listt B[k];

    switch (p)
    {
        
        case 1:
            cout << " Enter the algorithm no 1, 2, 3 or 5 for prob1. Algo 3 is t the end of this program: ";
            cin >> p;
            switch(p)
            {
                case 1:
                    int t;
                    struct megalist T;
                    cout<<"Enter the size of respective arrays:";
                    for(int i=0;i<k;i++)
                    {
                        cin>>t;
                        B[i].size=t;
                        B[i].ptr=0;
                    }
                    for(int j=0;j<k;j++)
                    {
                        cout<<"Enter the elements of array "<<j+1<<":";
                        for(int k=0;k<B[j].size;k++)
                        {
                            cin>>B[j].A[k];
                        }
                    }
                    T.size=B[0].size;
                    for(int i=0;i<T.size;i++)
                        T.M[i]=B[0].A[i];
                    for(int u=1;u<k;u++)
                        T=merge(B[u],T);
                    cout<<"Sorted array:";
                    for(int i=0;i<T.size;i++)
                        cout<<T.M[i]<<" ";
                    break;

                case 2:
                    cout<<"Enter the sizes of respective arrays:";
                    for(int y=0;y<k;y++)
                        cin>>L[y].size;
                    for(int i=0;i<k;i++)
                    {
                        cout<<"Enter array "<<i+1<<":";
                        for(int j=0;j<L[i].size;j++)
                            cin>>L[i].A[j];
                    }
                    struct listt R;
                    R=mergesort(0,k-1);
                    cout<<"Resultant array:";
                    for(int i=0;i<R.size;i++)
                        cout<<R.A[i]<<" ";
                    break;
                case 3:
                    /* code */
                    break;
                
                case 5:
                    int k;
                    int Final_Array_Size = 0;
                    
                    for(int i = 0; i < k; i++)
                    {
                        printf("Enter the size of %dth array:", i);
                        cin >> Unit_Array[i].size;
                        Final_Array_Size = Final_Array_Size + Unit_Array[i].size;
                        printf("Enter the elements of %dth array:", i);
                        for(int j = 0; j < Unit_Array[i].size; j++)
                            cin >> Unit_Array[i].arr[j];
                    }
                    Sorted_Array.resize(Final_Array_Size);
                    Sorted_Array = Sorter(Unit_Array, k, Final_Array_Size);
                    cout << "The sorted Array is:\n";
                    for(int i = 0; i < Final_Array_Size; i++)
                    {
                        cout << " " << Sorted_Array[i];
                    }
                    cout << endl;
                    break;
                
                default:
                    cout << "invalid algorithm no.\n";
                    break;
            }


        case 2:
            int arr[100000]={0};
            srand((unsigned)time(0));
            for(int i=0;i<100000;i++) //generating random array
                arr[i]=(rand()%100)*pow(10,rand()%3)*pow(-1,rand()%2);
            twowaymergesort(arr,0,99999);
            cout<<"Sorted array:";
            for(int i=0;i<100000;i++)
                cout<<arr[i]<<" ";
            break;
            
        default:
                cout << "invalid problem no.\n";
                break;
    }

//____________________Algo 3 problem 1 done here______________________________
    int S[k];
    node* root = NULL;
    cout << "Algo3 for problem1 starts:" << endl;
    cout<<"Enter the sizes of respective array:";
    for(int i=0;i<k;i++)
        cin>>S[i];
    int m=*max_element(S,S+k);
    int arr[100][m];
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < m; j++)
            arr[i][j] = 0;
    }
    for(int i=0;i<k;i++) //input
    {
        cout<<"Enter the elements of array "<<i+1<<":";
        for(int j=0;j<S[i];j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<S[i];j++)
            root=insert(root,arr[i][j]);
    }
    for(int i=0;i<k;i++)
    {
        cout<<"Elements of array "<<i+1<<":";
        for(int j=0;j<S[i];j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Union of "<<k<<" arrays:";
    inorder(root);
    return 0;
}

