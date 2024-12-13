#include <iostream>
using namespace std;

class Stack {
private:
    const static int size = 10; 
    int arr[size];
    int topIndex; 

public:
    Stack() : topIndex(-1) {} 

    void push(int x) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow!" << endl;
            return;
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
        return topIndex == size - 1;
    }

    int getsize() 
    {
        return size;
    }

    int getNumOfElems() 
    {
        return topIndex + 1;
    }

    Stack& operator=(const Stack& other) 
    {
        if (this != &other) 
        {
            topIndex = other.topIndex;
            for (int i = 0; i <= topIndex; i++) 
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    Stack(const Stack& other) 
    {
        topIndex = other.topIndex;
        for (int i = 0; i <= topIndex; i++) 
        {
            arr[i] = other.arr[i];
        }
    }
};

int main() 
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; 
    for (int i = 0; i < 1000; i++)
    {
    s.pop();
        /* code */
    }
    
    cout << "Top element after pop: " << s.top() << endl; 
    cout << "Stack size: " << s.getNumOfElems() << endl; 
    return 0;
}
