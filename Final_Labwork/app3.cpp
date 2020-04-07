#include"Lab3.h"
using namespace std;
int main()
{
    int swi;
    int N;
    int arr[50];
    while( true )
    {
        cout << "\nOperations:\n1.Sorting ( stable ) array of 0, 1, 2 in increasing order using selection subroutine\n2.Sorting ( stable ) array of 0, 1, 2 in increasing order using queue data structure\n3.Sorting ( stable ) array of 0, 1, 2 in increasing order using hashing technique\n4.Partitioning an array into two sub arrays such that their difference is minimum\n5.Exit\nEnter your choice : ";
        cin >> swi;
        switch( swi )
        {
            case 1:{    cout << "Enter the size of the array : ";
                        cin >> N;
                        cout << "Enter the elements : \n";
                        for(int i = 0; i < N; i++)
                            cin >> arr[i];
                        L1sort012(arr,N);
                        printArray(arr,N);
                        break;
                    }
            case 2:{
                        cout << "Enter the size of the array : ";
                        cin >> N;
                        cout << "Enter the elements : \n";
                        for(int i = 0; i < N; i++)
                            cin >> arr[i];
                        L2sort012(arr,N);
                        printArray(arr,N);
                        break;
                    }
            case 3:{
                        cout << "Enter the size of the array : ";
                        cin >> N;
                        cout << "Enter the elements : \n";
                        for(int i = 0; i < N; i++)
                            cin >> arr[i];
                        L3sort012(arr,N);
                        printArray(arr,N);
                        break;
                    }
            case 4:{
                        cout<<"Enter the size of the array:";
                        cin>>N;
                        int M=N/2;
                        int lrr[M];
                        int rrr[M];
                        cout<<"Enter the elements of the array:";
                        for(int i=0;i<N;i++)
                            cin>>arr[i];
                        sort(arr,arr+N);
                        for(int j=0;j<M;j++)
                        {
                            lrr[j]=arr[j];
                            rrr[j]=arr[M+j];
                        }
                        partition(arr,lrr,rrr,N);
                        printArray(lrr,M);
                        printArray(rrr,M);
                        break;
                    }
            case 5: exit(0);
                
            default: cout << "INVALID operation !";
        }
    }
    return 0;
}
        
