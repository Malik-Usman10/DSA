#include <iostream>
using namespace std;

template <typename T>
class deque {
private:
    T* arr;         
    int front;       
    int rear;       
    int size;      
    int capacity;   

public:
    deque(int maxSize = 100) 
    {
        capacity = maxSize;
        arr = new T[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~deque() 
    {
        delete[] arr;
    }

    bool isEmpty() const 
    {
        return front == -1;
    }


    bool isFull() const 
    {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }


    void insertFront(T element) 
    {
        if (isFull()) 
        {
            throw runtime_error("deque is full");
        }

        if (isEmpty()) 
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else 
        {
            front--;
        }

        arr[front] = element;
        size++;
    }

    void insertRear(T element) 
    {
        if (isFull()) 
        {
            throw runtime_error("deque is full");
        }

        if (isEmpty()) 
        {
            front = rear = 0;
        }
        else if (rear == capacity - 1) 
        {
            rear = 0;
        }
        else 
        {
            rear++;
        }

        arr[rear] = element;
        size++;
    }

    T deleteFront() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("deque is empty");
        }

        T element = arr[front];

        if (front == rear) 
        {
            front = rear = -1;
        }
        else if (front == capacity - 1) 
        {
            front = 0;
        }
        else 
        {
            front++;
        }

        size--;
        return element;
    }

    T deleteRear() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("deque is empty");
        }

        T element = arr[rear];

        if (front == rear) 
        {
            front = rear = -1;
        }
        else if (rear == 0) 
        {
            rear = capacity - 1;
        }
        else 
        {
            rear--;
        }

        size--;
        return element;
    }

    T getFront() const
    {
        if (isEmpty()) 
        {
            throw runtime_error("deque is empty");
        }
        return arr[front];
    }

    T getRear() const 
    {
        if (isEmpty()) 
        {
            throw runtime_error("deque is empty");
        }
        return arr[rear];
    }

    int getSize() const 
    {
        return size;
    }

    void display() const 
    {
        if (isEmpty()) 
        {
            cout << "deque is empty" << endl;
            return;
        }

        int i = front;
        cout << "deque elements: ";
        while (true) 
        {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() 
{
    try {
        deque<int> dq(5);  
        dq.insertFront(1);  
        dq.insertRear(2);   
        dq.insertFront(3);  
        
        dq.display(); 
        
        cout << "Deleted from front: " << dq.deleteFront() << endl;
        cout << "Deleted from rear: " << dq.deleteRear() << endl;
        
        dq.display(); 
        
    } catch (const runtime_error& e) 
    {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
