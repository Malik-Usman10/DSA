#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T info;
    Node<T> *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        Node<T> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->info = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->info = value;
        newNode->next = nullptr;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool deleteAtHead()
    {
        if (!head)
            return false;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    bool deleteAtTail()
    {
        if (!head)
            return false;
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return true;
        }
        Node<T> *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return true;
    }

    void printList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node<T> *getNode(int n)
    {
        if (head == nullptr)
            return nullptr;

        Node<T> *temp = head;
        int count = 0;

        while (temp != nullptr && count < n)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    bool insertAfter(T value, T key)
    {
        Node<T> *temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            Node<T> *newNode = new Node<T>;
            newNode->info = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        return false;
    }
    bool insertBefore(T value, T key)
    {
        if (head == nullptr)
            return false;

        if (head->info == key)
        {
            insertAtHead(value);
            return true;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr && temp->next->info != key)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            Node<T> *newNode = new Node<T>;
            newNode->info = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        return false;
    }
    bool deleteBefore(T key)
    {
        if (head == nullptr || head->next == nullptr || head->info == key)
            return false;

        if (head->next->info == key)
        {
            deleteAtHead();
            return true;
        }

        Node<T> *temp = head;
        while (temp->next->next != nullptr && temp->next->next->info != key)
        {
            temp = temp->next;
        }

        if (temp->next->next != nullptr)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }
    bool deleteAfter(T key)
    {
        Node<T> *temp = head;
        while (temp != nullptr && temp->info != key)
        {
            temp = temp->next;
        }

        if (temp != nullptr && temp->next != nullptr)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }
    int getLength()
    {
        int length = 0;
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    Node<T> *search(T x)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->info == x)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    Node<T>* getHead() const 
    {
        return head;
    }

    void setHead(Node<T>* newHead) 
    {
        head = newHead;
    }

    void reverseList()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        Node<T> *next = nullptr;

        while (current != nullptr)
        {
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        }
        head = prev; 
    }
};

#endif
