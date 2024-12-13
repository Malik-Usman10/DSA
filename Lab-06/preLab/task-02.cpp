#include <iostream>
using namespace std;

template <class T>
class QNode
{
public:
    T data;
    QNode *link;
};

template <class T>
class Queue
{
private:
    QNode<T> *front, *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    Queue(const Queue<T> &other)
    {
        if (other.front == nullptr)
        {
            front = rear = nullptr;
            size = 0;
            return;
        }

        // Copy the front node
        front = new QNode<T>;
        front->data = other.front->data;

        // Copy the rest of the nodes
        QNode<T> *tempOther = other.front->link;
        QNode<T> *tempThis = front;

        while (tempOther != nullptr)
        {
            tempThis->link = new QNode<T>;
            tempThis = tempThis->link;
            tempThis->data = tempOther->data;
            tempOther = tempOther->link;
        }

        rear = tempThis;
        rear->link = nullptr;
        size = other.size;
    }

    void enqueue(T element)
    {
        QNode<T> *temp = new QNode<T>;
        temp->data = element;
        temp->link = nullptr;
        if (rear == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->link = temp;
            rear = temp;
        }
        size++;
    }

    T dequeue()
    {
        if (front == nullptr)
        {
            throw underflow_error("Queue is empty");
        }
        QNode<T> *temp = front;
        T value = temp->data;
        front = front->link;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        size--;
        return value;
    }

    void display()
    {
        QNode<T> *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }
    int currentSize()
    {
        return size;
    }
    T frontElement()
    {
        if (front == nullptr)
        {
            throw underflow_error("Queue is empty");
        }
        return front->data;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    bool isFull()
    {
        return false;
    }
    ~Queue()
    {
        while (front != nullptr)
        {
            QNode<T> *temp = front;
            front = front->link;
            delete temp;
        }
        rear = nullptr;
    }
};
