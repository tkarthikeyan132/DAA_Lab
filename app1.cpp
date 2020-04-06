#include"BASIC.h"
using namespace std;
int main()
{
    int swi;
    int x,y,res;
    while(true)
    {
        cout << "\nOperations: \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Factorial\n6.Power\n7.Exit\nEnter your choice: ";
        cin >> swi;
        switch(swi)
        {
            case 1: cout << "Enter the elements: ";
                    cin >> x >> y;
                    res = Addition(x,y);
                    cout << "Result: " << res << endl;
                    break;
                    
            case 2: cout << "Enter the elements: ";
                    cin >> x >> y;
                    res = Subtraction(x,y);
                    cout << "Result: " << res << endl;
                    break;
                
            case 3: cout << "Enter the elements: ";
                    cin >> x >> y;
                    res = Multiplication(x,y);
                    cout << "Result: " << res << endl;
                    break;
                    
            case 4: cout << "Enter the dividend: ";
                    cin >> x;
                    cout << "Enter the divisor: ";
                    cin >> y;
                    res = Division(x,y);
                    if(res != NFDBITS)
                        cout << "Result: " << res << endl;
                    break;
                    
            case 5: cout << "Enter the element: ";
                    cin >> x;
                    res = Factorial(x);
                    cout << "Result: " << res << endl;
                    break;
                    
            case 6: cout << "Enter the number: ";
                    cin >> x;
                    cout << "Enter the power: ";
                    cin >> y;
                    res = Power(x,y);
                    cout << "Result: " << res << endl;
                    break;
                    
            case 7: exit(0);
            
            default: cout << "Invalid operation !" << endl;
        }
    }
    return 0;
}
