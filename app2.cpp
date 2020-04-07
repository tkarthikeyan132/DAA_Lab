#include"LINALG.h"
using namespace std;
int main()
{
    vector<vector<int>> a;
    a = {{1,2,3},{4,5,6}};
    vector<vector<int>> b;
    b = {{1,2,3},{4,5,6}};
    vector<vector<int>> c = Matrix_addition(a,2,3,b,2,3);
    for(int i=0;i<2;i++)
    {
        cout << endl;
        for(int j=0;j<3;j++)
            cout<<c[i][j]<<" ";
    }
    return 0;
}
    
