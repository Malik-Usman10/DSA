#include <iostream>
using namespace std;
int number_of_digits(int number) 
{
    if (number == 0) 
    {
        return 1;
    } 
    else if (number / 10 == 0) 
    {
        return 1;
    } 
    else 
    {
        return 1 + number_of_digits(number / 10);
    }
}

int main() 
{
    int number = -100;
    cout << "Number of digits: " << number_of_digits(number);
}