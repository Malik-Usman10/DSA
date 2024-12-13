#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size = 10) : capacity(size), topIndex(-1) 
    {
        arr = new int[capacity];
    }

    ~Stack() 
    {
        delete[] arr;
    }

    void push(int x) 
    {
        if (isFull()) 
        {
            resize();
        }
        arr[++topIndex] = x;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    int top() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() 
    {
        return topIndex == -1;
    }

    bool isFull() 
    {
        return topIndex == capacity - 1;
    }

    int getCapacity() 
    {
        return capacity;
    }

    int getNumOfElems() 
    {
        return topIndex + 1;
    }

private:
    void resize() 
    {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];
        for (int i = 0; i <= topIndex; i++) 
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
};

int main() 
{
    Stack d(5);

    for(int i=0; i<1000;i++){
    d.push(1);

    }
    d.push(2);
    d.push(3);
    d.push(4);
    d.push(5);
    d.push(6); 
    cout << "Top element: " << d.top() << endl; 
    cout << "Capacity: " << d.getCapacity() << endl; 
    cout << "Size of Stack: " << d.getNumOfElems() << endl; 
}
