#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Unit
{
    public:
        int size;    //size of the array
        int arr[50]; //the array of sorted integers with default size 50.
        int pointer; //pointer to the first index which produces.
        void initializer();
};

vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size);

int main()
{
    int k;
    int Final_Array_Size = 0;
    cout << "Enter the no. of arrays: ";
    cin >> k;
    Unit Unit_Array[k];
    for(int i = 0; i < k; i++)
    {
        printf("Enter the size of %dth array:", i);
        cin >> Unit_Array[i].size;
        Final_Array_Size = Final_Array_Size + Unit_Array[i].size;
        printf("Enter the elements of %dth array:", i);
        for(int j = 0; j < Unit_Array[i].size; j++)
            cin >> Unit_Array[i].arr[j];
    }
    vector<int> Sorted_Array(Final_Array_Size);
    Sorted_Array = Sorter(Unit_Array, k, Final_Array_Size);
    for(int i = 0; i < Final_Array_Size; i++)
    {
        cout << " " << Sorted_Array[i];
    }
    return 0;
}

vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size)
{
    int j = 0;
    vector<int> Temp(k);
    vector<int> Final_vector(Final_Array_Size);
    for(int i = 0; i < k; i++)
        Temp[i] = (-1) * Unit_Array[i].arr[Unit_Array[i].pointer];
    
    make_heap(Temp.begin(), Temp.end());
    Final_vector[j] = Temp.front();
    Temp.pop_back(); 


}

void Unit::initializer()
{
    pointer = 0;
}
