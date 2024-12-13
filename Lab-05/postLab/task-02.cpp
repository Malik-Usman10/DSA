#include <iostream>
#include "myQueue.h" 
using namespace std;

// FIFO --> LIFO
template <typename T>
class StackUsingQueues
{
private:
    MyLinearQueue<T> queue1;  
    MyLinearQueue<T> queue2; 

public:
    StackUsingQueues() {}

    void push(T element) 
    {
        queue1.enqueue(element);
        while (queue1.size() > 1) 
        {
            queue2.enqueue(queue1.dequeue());  // Rear exit to Front entry
        }

        MyLinearQueue<T> temp = queue1;
        queue1 = queue2;   // Q1 attain LIFO manner
        queue2 = temp;
    }

    T pop() 
    {
        if (queue1.isEmpty()) 
        {
            throw runtime_error("Stack is empty. Cannot pop.");
        }
        return queue1.dequeue();
    }

    bool isEmpty() const 
    {
        return queue1.isEmpty();
    }

    int size() const 
    {
        return queue1.size();
    }

    T top() const 
    {
        if (queue1.isEmpty()) {
            throw runtime_error("Stack is empty. Cannot retrieve top element.");
        }
        return queue1.getFront();
    }
};

int main() 
{
    StackUsingQueues<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top of the stack: " << myStack.top() << endl;
    cout << "Popped element: " << myStack.pop() << endl;
    cout << "Popped element: " << myStack.pop() << endl;

    cout << "Stack size after pops: " << myStack.size() << endl;
}
