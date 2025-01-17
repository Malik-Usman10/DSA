#include <iostream>
using namespace std;

int search(int* arr, int element, int array_size, int index = 0) 
{
    if (index >= array_size) 
    {
        return -1;
    }

    if (arr[index] == element) 
    {
        return index;
    }
    return search(arr, element, array_size, index + 1);
}

int main() 
{
    int array_size;
    cout << "Enter the size of the array: ";
    cin >> array_size;

    int* arr = new int[array_size];

    cout << "Enter " << array_size << " integers: ";
    for (int i = 0; i < array_size; i++) 
    {
        cin >> arr[i];
    }

    int element;
    cout << "Enter the element to search for: ";
    cin >> element;

    int result = search(arr, element, array_size);

    if (result == -1) 
    {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index " << result << "." << endl;
    }
    delete[] arr;
}