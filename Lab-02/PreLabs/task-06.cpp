#include <iostream>
using namespace std;

int binary_search(int* arr, int size, int target) 
{
    if (size == 0) 
    {
        return -1; 
    }

    int mid = size / 2;

    if (arr[mid] == target) 
    {
        return mid;
    } 
    else if (arr[mid] > target) 
    {
        int* new_arr = arr;
        int new_size = mid;
        return binary_search(new_arr, new_size, target);
    } 
    else 
    {
        int* new_arr = arr + mid + 1; // forward dekhy ga
        int new_size = size - mid - 1; // backward dekhy ga
        int result = binary_search(new_arr, new_size, target);
        if (result != -1) 
        {
            return result + mid + 1;
        } 
        else 
        {
            return -1;
        }
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binary_search(arr, size, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
}