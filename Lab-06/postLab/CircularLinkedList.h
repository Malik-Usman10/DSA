#ifndef CircularLinkedList_H
#define CircularLinkedList_H

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
class CircularLinkedList
{
private:
    Node<T> *head;

public:
    Node<T>* convertToLinear();
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        do
        {
            Node<T> *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = nullptr;
    }

    void insertAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->info = value;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    Node<T> *reverseKNodes(Node<T> *start, int k)
    {
        Node<T> *prev = nullptr, *current = start, *nextNode = nullptr;
        int count = 0;

        while (current != nullptr && count < k)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            count++;
        }

        start->next = current;
        return prev;
    }

    Node<T> *reverseKGroup(int k)
    {
        if (head == nullptr || k <= 1)
            return head;

        Node<T> *dummy = new Node<T>();
        dummy->next = head;
        Node<T> *groupPrev = dummy, *groupEnd = head;

        while (true)
        {
            int i = 0;
            for (; i < k && groupEnd != head; i++)
                groupEnd = groupEnd->next;

            if (i < k)
                break;

            Node<T> *groupStart = groupPrev->next;
            Node<T> *nextGroupStart = groupEnd->next;

            groupEnd->next = nullptr;
            groupPrev->next = reverseKNodes(groupStart, k);
            groupStart->next = nextGroupStart;

            groupPrev = groupStart;
            groupEnd = groupStart->next;
        }

        head = dummy->next;
        delete dummy;

        return head;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = head;
        do
        {
            cout << temp->info << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }


    Node<T> *getHead()
    {
        return head;
    }


    void removeHead()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        Node<T> *oldHead = head;
        head = head->next;
        temp->next = head;
        delete oldHead;
    }

    void removeAfter(Node<T> *prev)
    {
        if (prev == nullptr || prev->next == nullptr)
            return;

        Node<T> *toDelete = prev->next;
        prev->next = toDelete->next;

        if (toDelete == head)
        {
            head = prev->next;
        }

        delete toDelete;
    }
    void displayCircular(int repetitions = 2);  
    void displayLinear();  
};

#endif