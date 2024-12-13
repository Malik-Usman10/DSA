#include "LinkedList.h"
#include <iostream>
using namespace std;

Node<int>* mergeSorted(const LinkedList<int>& list1, const LinkedList<int>& list2) 
{
    Node<int>* result = nullptr;
    Node<int>** lastPtrRef = &result;
    
    Node<int>* current1 = list1.getHead();
    Node<int>* current2 = list2.getHead();

    while (current1 != nullptr && current2 != nullptr) 
    {
        if (current1->info <= current2->info)
        {
            *lastPtrRef = new Node<int>;
            (*lastPtrRef)->info = current1->info;
            current1 = current1->next;
        } 
        else 
        {
            *lastPtrRef = new Node<int>;
            (*lastPtrRef)->info = current2->info;
            current2 = current2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (current1 != nullptr) 
    {
        *lastPtrRef = new Node<int>;
        (*lastPtrRef)->info = current1->info;
        lastPtrRef = &((*lastPtrRef)->next);
        current1 = current1->next;
    }

    while (current2 != nullptr) 
    {
        *lastPtrRef = new Node<int>;
        (*lastPtrRef)->info = current2->info;
        lastPtrRef = &((*lastPtrRef)->next);
        current2 = current2->next;
    }

    return result;
}

int main()
{
    LinkedList<int> list1;
    list1.insertAtHead(4);
    list1.insertAtHead(2);
    list1.insertAtHead(0);

    LinkedList<int> list2;
    list2.insertAtHead(5);
    list2.insertAtHead(3);
    list2.insertAtHead(1);

    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();

    Node<int> *mergedHead = mergeSorted(list1, list2);

    cout << "Merged list: ";
    Node<int> *current = mergedHead;
    while (current != nullptr) 
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;

    while (mergedHead != nullptr) 
    {
        Node<int> *temp = mergedHead;
        mergedHead = mergedHead->next;
        delete temp;
    }

    return 0;
}






















