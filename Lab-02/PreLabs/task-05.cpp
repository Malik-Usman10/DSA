#include <iostream>
using namespaces std;

int binary_search(int* arr, int left, int right, int target) 
{
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            return mid;
        } 
        else if (arr[mid] > target) 
        {
            return binary_search(arr, left, mid - 1, target);
        } 
        else 
        {
            return binary_search(arr, mid + 1, right, target);
        }
    } 
    else 
    {
        return -1; 
    }
}

int main() 
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binary_search(arr, 0, n - 1, target);

    if (result != -1) 
    {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
}