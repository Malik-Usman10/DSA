#include <iostream>
using namespace std;

int gcd(int fNum, int sNum)
{
    if (sNum == 0)                                  
    {
        return fNum; 
    }
    else
    {
        return gcd(sNum, fNum % sNum);
    }
}

int main()
{
    int fNum, sNum;
    cout << "Enter the First Number: " << endl;
    cin >> fNum;
    cout << "Enter the Second Number: " << endl;
    cin >> sNum;
    int result = gcd(fNum, sNum);
    cout << "The GCD of the Given Numbers is: " << result << endl;
}