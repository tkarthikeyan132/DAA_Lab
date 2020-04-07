#include"LINALG.h"
using namespace std;
int main()
{
    int m,n,x,y,swi;
    vector<vector<int>> a;
    vector<vector<int>> b;
    cout << "Enter the number of rows and columns of first array : ";
    cin >> m >> n;
    a.resize(m);
    cout << "Enter the first array :\n";
    for(int i = 0; i < m ; i++)
    {
        a[i].resize(n);
        for(int j = 0; j < n ; j++)
            cin >> a[i][j];
    }
    cout << "Enter the number of rows and columns of second array : ";
    cin >> x >> y;
    b.resize(x);
    cout << "Enter the second array :\n";
    for(int i = 0; i < x ; i++)
    {
        b[i].resize(n);
        for(int j = 0; j < y ; j++)
            cin >> b[i][j];
    }
    while(true)
    {
        cout << "\nOperations :\n1.Matrix Addition\n2.Matrix Multiplication\n3.Exit\nEnter your choice : ";
        cin >>swi;
        switch(swi)
        {
            case 1:{
                     vector<vector<int>> c = Matrix_addition(a,m,n,b,x,y);
                     cout << "Result matrix : \n";
                     printMatrix(c);
                     break;
                   }   
                     
            case 2:{
                     vector<vector<int>> c = Matrix_multiplication(a,m,n,b,x,y);
                     cout << "Result matrix : \n";
                     printMatrix(c);
                     break;
                   }  
            case 3:  exit(0);
            
            default: cout << "INVALID operation !";
        }
    }
    return 0;
}
