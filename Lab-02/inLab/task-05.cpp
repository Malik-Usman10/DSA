#include<iostream>
using namespace std;

void printTriangle(int n) 
{
    if( n > 0 )
    {
        cout << string(n,'*') << endl;
        star(n-1);
    }
}
int main() 
{
    int rows;
    cout << "Enter the Numbers of Rows:" << endl;
    cin >> rows;
    printTriangle(rows);
}



















 

