#include <iostream>
using namespace std;

template <class T>
class StackNode
{
public:
    T data;
    StackNode *link;
};

template <class T>
class Stack
{
private:
    StackNode<T> *Top;
    int Size;

public:
    Stack() : Top(nullptr), Size(0) {}
    Stack(const Stack<T> &other)
    {
        if (other.Top == nullptr)
        {
            Top = nullptr;
            Size = 0;
            return;
        }

        // Copy the top node
        Top = new StackNode<T>;
        Top->data = other.Top->data;

        // Copy the rest of the nodes
        StackNode<T> *tempOther = other.Top->link;
        StackNode<T> *tempThis = Top;

        while (tempOther != nullptr)
        {
            tempThis->link = new StackNode<T>;
            tempThis = tempThis->link;
            tempThis->data = tempOther->data;
            tempOther = tempOther->link;
        }

        tempThis->link = nullptr;
        Size = other.Size;
    }

    void push(T element)
    {
        StackNode<T> *temp = new StackNode<T>;
        temp->data = element;
        temp->link = Top;
        Top = temp;
        Size++;
    }

    T pop()
    {
        if (Top == nullptr)
            throw underflow_error("Stack is empty");
        StackNode<T> *temp = Top;
        T value = temp->data;
        Top = Top->link;
        delete temp;
        Size--;
        return value;
    }

    void display()
    {
        StackNode<T> *temp = Top;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }
    T getTop()
    {
        if (Top == nullptr)
        {
            throw underflow_error("Stack is empty");
        }
        return Top->data;
    }
    int currSize()
    {
        return Size;
    }
    bool isEmpty()
    {
        return Top == nullptr;
    }
    bool isFull()
    {
        return false;
    }
    T Peek(int nodeNumber)
    {
        if (nodeNumber < 1 || nodeNumber > Size)
        {
            throw out_of_range("Invalid node number");
        }

        StackNode<T> *temp = Top;
        int count = 1;

        while (temp != nullptr && count < nodeNumber)
        {
            temp = temp->link;
            count++;
        }

        return temp->data;
    }
    ~Stack()
    {
        while (Top != nullptr)
        {
            StackNode<T> *temp = Top;
            Top = Top->link;
            delete temp;
        }
    }
};
