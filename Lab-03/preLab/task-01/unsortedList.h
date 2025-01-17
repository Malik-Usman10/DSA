// UnsortedList.h
#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class UnsortedList {
private:
    T* arr;
    int maxSize;
    int currSize;

public:
    UnsortedList(int size = 10);  // Default size is 10
    ~UnsortedList();
    UnsortedList(const UnsortedList& other);
    const UnsortedList& operator=(const UnsortedList& other);

    bool insert(const T& val);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    bool remove(int index);
};

#endif 


