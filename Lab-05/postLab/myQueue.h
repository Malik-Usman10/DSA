#ifndef MYQUEUE_H
#define MYQUEUE_H

#include<iostream>
using namespace std;
template<typename T>
class MyLinearQueue {
private:
    int rearIndex;         
    int frontIndex;        
    int queueCapacity;     
    int numberOfElements;  
    T* queueData;        
    // Time Complexity: O(n) where n is the number of elements
    // Space Complexity: O(n) for the new array
    void resize(int newSize) 
    {
        T* newData = new T[newSize];
        // Copy existing elements to new array
        for (int i = 0; i < numberOfElements; i++) 
        {
            newData[i] = queueData[(frontIndex + i) % queueCapacity];
        }
        delete[] queueData;
        queueData = newData;
        frontIndex = 0;
        rearIndex = numberOfElements - 1;
        queueCapacity = newSize;
    }

public:
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    MyLinearQueue() 
    {
        rearIndex = -1;
        frontIndex = 0;
        numberOfElements = 0;
        queueCapacity = 1;
        queueData = new T[queueCapacity];
    }

    // Copy constructor
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    MyLinearQueue(const MyLinearQueue<T>& other) 
    {
        queueCapacity = other.queueCapacity;
        numberOfElements = other.numberOfElements;
        frontIndex = 0;
        rearIndex = numberOfElements - 1;
        queueData = new T[queueCapacity];
        
        for (int i = 0; i < numberOfElements; i++) 
        {
            queueData[i] = other.queueData[(other.frontIndex + i) % other.queueCapacity];
        }
    }

    // Assignment operator
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    MyLinearQueue<T>& operator=(const MyLinearQueue<T>& other) 
    {
        if (this != &other) 
        {
            delete[] queueData;
            
            queueCapacity = other.queueCapacity;
            numberOfElements = other.numberOfElements;
            frontIndex = 0;
            rearIndex = numberOfElements - 1;
            queueData = new T[queueCapacity];
            
            for (int i = 0; i < numberOfElements; i++) 
            {
                queueData[i] = other.queueData[(other.frontIndex + i) % other.queueCapacity];
            }
        }
        return *this;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    ~MyLinearQueue() 
    {
        delete[] queueData;
    }

    // Time Complexity: O(n) if resize needed, O(1) otherwise
    // Space Complexity: O(n) if resize needed, O(1) otherwise
    void enqueue(const T element) 
    {
        if (numberOfElements == queueCapacity) 
        {
            resize(queueCapacity * 2);
        }
        rearIndex = (rearIndex + 1) % queueCapacity;
        queueData[rearIndex] = element;
        numberOfElements++;
    }

     void enqueueFront(const T element) {
        if (numberOfElements == queueCapacity)
        {
            resize(queueCapacity * 2);
        }
        // Adjust front index to make space for new front element
        frontIndex = (frontIndex - 1 + queueCapacity) % queueCapacity;
        queueData[frontIndex] = element;
        numberOfElements++;
    }


    // Remove and return the front element
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    T dequeue() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        T element = queueData[frontIndex];
        frontIndex = (frontIndex + 1) % queueCapacity;
        numberOfElements--;
        return element;
    }
    T dequeueRear()
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        T element = queueData[rearIndex];
        rearIndex = (rearIndex - 1 + queueCapacity) % queueCapacity;
        numberOfElements--;
        return element;
    }

    // Get the front element without removing it
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    T getFront() const 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        return queueData[frontIndex];
    }

    // Check if the queue is empty
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isEmpty() const 
    {
        return numberOfElements == 0;
    }

    // Check if the queue is full
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isFull() const 
    {
        return numberOfElements == queueCapacity;
    }

    // Get the current number of elements
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int size() const 
    {
        return numberOfElements;
    }

    // Get the maximum capacity of the queue
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int getCapacity() const 
    {
        return queueCapacity;
    }
};

#endif