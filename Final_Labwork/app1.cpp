#include "Lab1.h"

int main()
{
    int a, b, n, it;
    cout << "Enter two numbers for GCD calculation: ";
    cin >> a >> b;
    cout << "Enter the algorithm no from 1 to 3: ";
    cin >> n;
    cout << "Enter 1 for iterative implementation, for recursive enter 0: ";
    cin >> it;
    switch (it)
    {
        case 0:
            switch (n)
            {
                case 1:
                    cout << gcd1_rec(abs(a), abs(b), std::min(abs(a),abs(b))) << endl;
                    break;
                case 2:
                    cout << gcd2_rec(abs(a), abs(b)) << endl;
                    break;
                case 3:
                    cout << gcd3_rec(abs(a), abs(b)) << endl;
                    break;
                
                default:
                    break;
            }
            break;

        case 1:
            switch (n)
            {
                case 1:
                    cout << gcd1_it(abs(a), abs(b)) << endl;
                    break;
                case 2:
                    cout << gcd2_it(abs(a), abs(b)) << endl;
                    break; 
                case 3:
                    cout << gcd3_it(abs(a), abs(b)) << endl;
                    break;
                
                default:
                    break;
            }
            break;
    }
    
 //------------------------------------------------------------------------------------------------------    
    int size;
    cout << "Enter the array size to calculate GCD: ";
    cin >> size;
    int arr[size];
    cout << "Enter the array of integers: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter 1 for iterative implementation, for recursive enter 0: ";
    cin >> it;
    cout << "GCD is: ";
    switch(it)
    {
        case 0:
            cout << gcda_rec(arr, size) << endl;
        case 1:
            cout << gcda_it(arr, size) << endl;
    }
    return 0;
}
