#include <iostream>
using namespace std;

int pow(int number, int power) 
{
    if (power == 0) 
    {
        return 1;
    }
    return number * pow(number, power - 1);
}

int main() 
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int power;
    cout << "Enter the power: ";
    cin >> power;

    int result = pow(number, power);

    cout << "The result is: " << result << endl;
}