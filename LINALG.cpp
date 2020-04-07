#include"LINALG.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> Matrix_addition(vector<vector<int>> arr,int m,int n,vector<vector<int>> brr,int x,int y)
{
    vector<vector<int>> c;
    if( m == x && n == y )
    {
        for(int i = 0; i < m; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
                temp.push_back(arr[i][j]+brr[i][j]);
            c.push_back(temp);
        }
    }
    else
        cout << "ERROR";
    return c;
}
