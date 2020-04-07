#include "Lab6.h"

//int z;
//stack <int> h[10000];

int main()
{
    int s;
    cout << "Enter the algorithm no. 1, 4 or 5: ";
    cin >> s;
    int n1,n2;
    cout<<"Enter a number:";
    cin>>n1;
    switch (s)
    {
        case 1:
            n2=dectobin(n1);
            int res=bm(n2,n2);
            cout<<"Square of the number in binary format:"<<res<<endl;
            break;
        
        case 4:
            n2=sqrt(n1);
            int count=0;
            for(int j=2;j<=n2;j++)
            {
                if(divide1(n1,j))
                    count++;
            }
            if(count)
                cout<<n1<<" is not a prime number"<<endl;
            else
                cout<<n1<<" is a prime number"<<endl;
            break;

        case 5:
            n2=sqrt(n1);
            int count=0;
            for(int j=2;j<=n2;j++)
            {
                if(divide2(n1,j))
                    count++;
            }
            if(count)
                cout<<n1<<" is not a prime number"<<endl;
            else
                cout<<n1<<" is a prime number"<<endl;
            break;
        
        default:
            cout << "INVALID INPUT, PROGRAM PROCEEDS" << endl;
            break;
    }
    
    cout << "Enter the algorithm no. 2 or 6: ";
    cin >> s;
    int N;
    cout<<"Enter the number of elements in array:";
    cin>>N;
    int A[N];
    struct node arr[N];
    switch (s)
    {
        case 2:
            cout<<"Enter the elements:";
            for(int k=0;k<N;k++)
                cin>>A[k];
            cout<<"How many smaller elements needed:";
            cin>>z;
            quicksort(A,0,N-1,z);
            cout<<"First k smallest elements:";
            for(int i=0;i<z;i++)
                cout<<A[i]<<" ";
            break;

        case 6:
            for(int i=0;i<N;i++)
                arr[i].index=i;
            cout<<"Enter the  elements:";
            for(int i=0;i<N;i++)
                cin>>arr[i].data;
            struct node res=tourna(arr,N);
            int secondmax;
            secondmax=findmax(h[res.index]);
            cout<<"Second maximum:"<<secondmax<<endl;
            break;
        
        default:
            cout << "INVALID INPUT, try again." << endl;
            break;
    }
    return 0;
}

    


    



    