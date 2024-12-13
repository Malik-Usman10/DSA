#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

template <class T>
void CircularLinkedList<T>::displayCircular(int repetitions)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node<T>* temp = head;
    int count = 0;
    int totalNodes = 0;
    
    Node<T>* counter = head;
    do
    {
        totalNodes++;
        counter = counter->next;
    } while (counter != head);

    do
    {
        cout << temp->info;
        temp = temp->next;
        count++;
        
        if (count < totalNodes * repetitions)
        {
            cout << " -> ";
        }
    } while (count < totalNodes * repetitions);
}

template <class T>
void CircularLinkedList<T>::displayLinear()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node<T>* temp = head;
    do
    {
        cout << temp->info;
        temp = temp->next;
        if (temp != head)
            cout << " -> ";
        else
            cout << " -> NULL";
    } while (temp != head);
}

template <class T>
Node<T>* CircularLinkedList<T>::convertToLinear()
{
    if (head == nullptr || head->next == head)
    {
        return head;
    }

    Node<T>* last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    last->next = nullptr;
    return head;
}

int main()
{
    CircularLinkedList<int> route;

    route.insertAtEnd(1);  
    route.insertAtEnd(2);  
    route.insertAtEnd(3);  
    route.insertAtEnd(4);  
    route.insertAtEnd(5);  

    cout << "Original Circular Route: \n";
    cout << "Showing circular nature (repeating twice): \n";
    route.displayCircular(2);  
    cout << "\n\n";

    Node<int>* linearHead = route.convertToLinear();

    cout << "Converted Linear Route: \n";
    Node<int>* current = linearHead;
    while (current != nullptr)
    {
        cout << current->info;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;

    while (linearHead != nullptr)
    {
        Node<int>* temp = linearHead;
        linearHead = linearHead->next;
        delete temp;
    }

    return 0;
}