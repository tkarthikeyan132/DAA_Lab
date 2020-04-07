#include"LINALG.h"

vector<vector<int>> Matrix_addition(vector<vector<int>> arr,int m,int n,vector<vector<int>> brr,int x,int y)
{
    if ( m == x && n == y )
    {
        vector<vector<int>> c(m);  //make vector (of vectors) of size m
        {
            for(int i = 0; i < m; i++)
            {
                c[i].resize(n);
                for(int j = 0; j < n; j++)
                    c[i][j] = arr[i][j]+brr[i][j];
            }
        }
        return c;
    }
    else
    {
        cout << "matrices are not addition compatible";
    }
}
vector<vector<int>> Matrix_multiplication(vector<vector<int>> arr,int m,int n,vector<vector<int>> brr,int x,int y)
{
    if( n != x )
    {
        cout << "Matrices are not multiplication compatible";
    }
    else
    {
        vector<vector<int>> c(m);
        if(n == x)
        {
            for(int i = 0; i < m; i++)
            {
                c[i].resize(y);
                for(int j = 0; j < y; j++)
                {
                    int tem = 0;
                    for(int k = 0;k < n; k++)
                        tem += arr[i][k] * brr[k][j];
                    c[i][j] = tem;
                }
            }
        }
        return c;
    }
}
void printMatrix(vector<vector<int>> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
            cout<<arr[i][j]<<" ";
        cout << endl;
    }
}
