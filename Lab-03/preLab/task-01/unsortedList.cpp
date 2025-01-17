#include "UnsortedList.h"

template <typename T>
UnsortedList<T>::UnsortedList(int size) : maxSize(size), currSize(0) 
{
    arr = new T[maxSize]; 
}

template <typename T>
UnsortedList<T>::~UnsortedList() 
{
    delete[] arr;
}

template <typename T>
UnsortedList<T>::UnsortedList(const UnsortedList& other) : 
    maxSize(other.maxSize), currSize(other.currSize) 
    {
    arr = new T[maxSize];
    for (int i = 0; i < currSize; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
const UnsortedList<T>& UnsortedList<T>::operator=(const UnsortedList& other) 
{
    if (this != &other) 
    {  
        delete[] arr;
        maxSize = other.maxSize;
        currSize = other.currSize;
        arr = new T[maxSize];
        for (int i = 0; i < currSize; ++i) 
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
bool UnsortedList<T>::insert(const T& val) 
{
    if (isFull()) 
    {
        throw std::runtime_error("List is Full! Cannot insert.");
    }

    arr[currSize++] = val;
    return true;
}

template <typename T>
bool UnsortedList<T>::isFull() const 
{
    return currSize == maxSize;
}

template <typename T>
bool UnsortedList<T>::isEmpty() const 
{
    return currSize == 0;
}

template <typename T>
void UnsortedList<T>::display() const 
{
    if(isEmpty()) 
    {
        std::cout << "List is Empty!" << std::endl;
        return;
    }
    std::cout << "List: ";
    for (int i = 0; i < currSize; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool UnsortedList<T>::remove(int index) 
{
    if (index < 0 || index >= currSize) 
    {
        throw std::out_of_range("Invalid index for removal.");
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < currSize - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    currSize--; 
    return true; 
}
