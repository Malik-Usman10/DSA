#include <iostream>
#include <cstdlib>    

using namespace std;

void allocateArray(int*** &arr, int n = 3) 
{
    arr = new int**[n]; 
    for (int i = 0; i < n; i++) 
    {
        arr[i] = new int*[n];  
        for (int j = 0; j < n; j++) 
        {
            arr[i][j] = new int[n]; 
        }
    }
}

void initializeArray(int*** arr, int n = 3) 
{
    srand(time(0));  
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++)
            {
                arr[i][j][k] = rand() % 100;
            }  
        }
    }
}

void printArray(int*** arr, int n = 3) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Plane " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                cout << arr[i][j][k] << " ";  
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray(int*** &arr, int n = 3) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            delete[] arr[i][j];  
        }
        delete[] arr[i];  
    }
    delete[] arr;  
    arr = nullptr;  
}

int main() 
{
    int n = 3;
    int*** arr = nullptr;


    allocateArray(arr, n);
    initializeArray(arr, n);
    printArray(arr, n);
    deallocateArray(arr, n);
}