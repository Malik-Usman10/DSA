#include <iostream>
using namespace std;

void rowMajorND(int dimensions)
{
    for (int i = 1; i <= dimensions ; i++)
    {
        cout << "i" << i;
        if (i < dimensions)
        {
            cout << " * ";
            for (int k = i + 1; k <= dimensions; k++)
            {
                cout << "D" << k;
                if (k < dimensions)
                {
                    cout << " * ";
                }
            }
            cout << " + ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the Number of the Row Major ND: " << endl;
    cin >> n;
    rowMajorND(n);
}
