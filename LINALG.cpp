#include"LINALG.h"

vector<vector<int>> Matrix_addition(vector<vector<int>> arr,int m,int n,vector<vector<int>> brr,int x,int y)
{
    vector<vector<int>> c(m);  //make vector (of vectors) of size m
    if( m == x && n == y )
    {
        for(int i = 0; i < m; i++)
        {
            c[i].resize(n);
            for(int j = 0; j < n; j++)
                c[i][j] = arr[i][j]+brr[i][j];
        }
    }
    else
        cout << "ERROR";
    return c;
}
