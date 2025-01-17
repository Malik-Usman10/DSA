#include <iostream>
using namespace std;

int squares_sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int squareSum = n * n + squares_sum(n-1);
    return squareSum;
}
int main()
{
    int num;
    cout << "Enter the Number: " << endl;
    cin >> num;
    int result = squares_sum(num);
    cout << "The Square Sum of |" << num << "| is: " << result << endl;
}