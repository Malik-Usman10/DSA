#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
using namespace std;


template <class T>
class DList;

template <class T>
class DNode {
    friend class DList<T>;
public:
    DNode<T>* next;
    DNode<T>* prev;
    T info;  
    DNode(T val) : info(val), next(nullptr), prev(nullptr) {}
};

template <class T>
class DList {
    DNode<T>* tail;
    int length;

public:
    DNode<T>* head;
    DList() : head(nullptr), tail(nullptr), length(0) {}

    ~DList() 
    {
        while (deleteAtHead());
    }

    DList(const DList<T>& other) : head(nullptr), tail(nullptr), length(0) 
    {
        DNode<T>* temp = other.head;
        while (temp) 
        {
            insertAtTail(temp->info);
            temp = temp->next;
        }
    }

    void insertAtHead(T value) 
    {
        DNode<T>* newNode = new DNode<T>(value);
        if (!head) 
        {  // Empty list case
            head = tail = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void insertAtTail(T value) 
    {
        DNode<T>* newNode = new DNode<T>(value);
        if (!tail) 
        {  
            head = tail = newNode;
        } 
        else 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    bool deleteAtHead() 
    {
        if (!head) return false;
        DNode<T>* temp = head;
        if (head == tail) 
        { 
            head = tail = nullptr;
        } 
        else 
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    bool deleteAtTail() 
    {
        if (!tail) return false;
        DNode<T>* temp = tail;
        if (head == tail) 
        {  
            head = tail = nullptr;
        } 
        else 
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
        return true;
    }

    void printList() const 
    {
        DNode<T>* temp = head;
        while (temp) 
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    DNode<T>* getNode(int n) const 
    {
        if (n < 0 || n >= length) return nullptr;
        DNode<T>* temp = head;
        for (int i = 0; i < n; ++i) 
        {
            temp = temp->next;
        }
        return temp;
    }

    bool insertAfter(T value, T key) 
    {
        DNode<T>* current = search(key);
        if(!current)
        {
            return false;
        }
        
        DNode<T>* newNode = new DNode<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) 
        {
            current->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
        length++;
        return true;
    }

    bool insertBefore(T value, T key) 
    {
        DNode<T>* current = search(key);
        if (!current) 
        {
            return false;
        }
        
        DNode<T>* newNode = new DNode<T>(value);
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev)
        {
            current->prev->next = newNode;
        } 
        else 
        {
            head = newNode;
        }
        current->prev = newNode;
        length++;
        return true;
    }

    bool deleteBefore(T key) 
    {
        DNode<T>* current = search(key);
        if (!current || !current->prev) 
        {
            return false;
        }
        DNode<T>* temp = current->prev;
        if (temp->prev) 
        {
            temp->prev->next = current;
        }
        else 
        {
            head = current;
        }
        current->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    bool deleteAfter(T key) 
    {
        DNode<T>* current = search(key);
        if (!current || !current->next) 
        {
            return false;
        }
        DNode<T>* temp = current->next;
        current->next = temp->next;
        if (temp->next) 
        {
            temp->next->prev = current;
        } 
        else {
            tail = current;
        }
        delete temp;
        length--;
        return true;
    }

    int getLength() const 
    {
        return length;
    }

    DNode<T>* search(T x) const 
    {
        DNode<T>* temp = head;
        while (temp) 
        {
            if (temp->info == x) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};
#endif