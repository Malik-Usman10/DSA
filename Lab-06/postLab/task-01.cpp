#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
Node<T>* reverseKGroup(Node<T>* head, int k) 
{
    if (head == nullptr || k == 1) 
    {
        return head;
    }

    Node<T>* temp = head;
    int count = 0;
    while (temp != nullptr) 
    {
        count++;
        temp = temp->next;
    }

    Node<T>* dummy = new Node<T>;
    dummy->next = head;
    Node<T>* prev = dummy;
    Node<T>* curr;
    Node<T>* next;

    while (count >= k) 
    {
        curr = prev->next;  
        next = curr->next;  

        for (int i = 1; i < k; i++) 
        {                              
            curr->next = next->next;   
            next->next = prev->next;    
            prev->next = next;          
            next = curr->next;         
        }

        prev = curr;
        count -= k;
    }

    head = dummy->next;
    
    delete dummy;
    
    return head;
}

int main() 
{
    LinkedList<int> list1;
    list1.insertAtTail(1);
    list1.insertAtTail(2);
    list1.insertAtTail(3);
    list1.insertAtTail(4);
    list1.insertAtTail(5);

    cout << "Original List 1: ";
    list1.printList();

    Node<int>* newHead1 = reverseKGroup(list1.getHead(), 2);
    list1.setHead(newHead1);

    cout << "Reversed List 1 (k=2): ";
    list1.printList();

    // LinkedList<int> list2;
    // list2.insertAtTail(1);
    // list2.insertAtTail(2);
    // list2.insertAtTail(3);
    // list2.insertAtTail(4);
    // list2.insertAtTail(5);

    // cout << "\nOriginal List 2: ";
    // list2.printList();

    // Node<int>* newHead2 = reverseKGroup(list2.getHead(), 3);
    // list2.setHead(newHead2);

    // cout << "Reversed List 2 (k=3): ";
    // list2.printList();

    return 0;
}