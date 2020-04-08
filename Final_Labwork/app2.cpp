#include "Lab2.h"

//int fibs[47]={0,1}; // initialise fibs[0] and fibs[1], fibs[i] is i'th fibonacci number
int main()
{
    int size, sum, n;
    cout << "Enter the size of the array to check if there exist two no's in array which sum up to a number 'sum': ";
    cin >> size;
    int arr[size];
    cout << "Enter the array element: " ;
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the another number 'sum': ";
    cin >> sum;
    cout << "Enter the algorithm no. from 1 to 4: ";
    cin >> n;
    switch (n)
    {
        case 1:
            if(bruteforcesum(arr, size, sum))
                cout<<"Yes possible"<<endl;
            else
                cout<<"Not possible"<<endl;
            break;
        
        case 2:
            if(leftrightsum(arr, size, sum))
                cout<<"Yes possible"<<endl;
            else
                cout<<"Not possible"<<endl;
            break;
        
        case 3:
            if(hashsum(arr, size, sum))
                cout<<"Yes possible"<<endl;
            else
                cout<<"Not possible"<<endl;
            break;
        
        case 4:
            if(binschsum(arr, size, sum))
                cout<<"Yes possible"<<endl;
            else
                cout<<"Not possible"<<endl;
            break;
        default:
            cout << "Invalid input, Try again." << endl;
            break;
    }

//--------------------------second question-------------------
    int A[10000];
    for(int i=0;i<10000;i++)
        A[i]=-1;
    int i=0,x=0;
    cout << "Start entering another array, when you enter -1, you signal the program to stop accepting values: " << endl;
    while(x!=-1)
    {
        cin>>x;
        A[i]=x;
        i++;
    }
    cout << "Enter the algorithm no. from 1 to 3 to detect the first (-1): ";
    cin >> n;
    int m;
    switch (n)
    {
        case 1:{
            m = binmark(A);
            if(m == -1)
                cout << "-1 not found"<<endl;
            int k = binminone(A, m/2, m);
            cout << "first -1 is found at "<<k+1<<" position"<<endl;
            break;}
        
        case 2:{
            for(int i=2;i<47;i++) // fibonacci number generation
                fibs[i]=fibs[i-1]+fibs[i-2];
            m = fibmark(A);
            if(m==-1)
                cout<<"-1 not found"<<endl;
            else
            {
                int y=binminone(A,fibs[m-1],fibs[m]);
                cout<<"first -1 is found at "<<y+1<<"th position"<<endl;
            }
            break;}
        
        case 3:{
            m = linminone(A);
            if(m!=-2)
                cout<<"first -1 is found at "<< m+1 <<" position"<< endl;
            else
                cout<< "-1 not found" << endl;
            break;}

        default:
            cout << "INVALID INPUT, TRY AGAIN." << endl;
            break;
    }

//------------------------------pattern-printing-----------------------

    cout << "\nEnter the no. for the patterns to be printed: ";
    cin >> n;

    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);

    return 0;
} 