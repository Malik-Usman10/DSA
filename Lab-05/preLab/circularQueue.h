#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include<iostream>
using namespace std;

template <class T>
class CircularQueue {
private:
    int front;      
    int rear;      
    int capacity;  
    int count;      
    T* queueArray; 

public:
    // Constructor
    // Time Complexity: O(1)
    // Space Complexity: O(n) where n is the size parameter
    CircularQueue(int size) 
    {
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
        queueArray = new T[capacity];
    }

    // Destructor
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    ~CircularQueue() 
    {
        delete[] queueArray;
    }

    // Add element to queue
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void enqueue(const T& data) 
    {
        if (isFull()) 
        {
            throw runtime_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        queueArray[rear] = data;
        count++;
    }

    // Remove and return front element
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    T dequeue() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        T element = queueArray[front];
        front = (front + 1) % capacity;
        count--;
        return element;
    }

    // Check if queue is empty
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isEmpty() const 
    {
        return count == 0;
    }

    // Check if queue is full
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isFull() const 
    {
        return count == capacity;
    }

    // Get current size of queue
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int size() const 
    {
        return count;
    }

    // View front element without removing it
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    T peek() const 
    {
        if (isEmpty()) 
        {
            throw runtime_error("Queue is empty");
        }
        return queueArray[front];
    }
};
#endif