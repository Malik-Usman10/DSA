#include "doubleLinkedList.h"
using namespace std;

DNode<int>* rotateRight(DNode<int>* head, int k)
{
    if (!head || !head->next || k == 0) 
    {
        return head;
    }

    DNode<int>* tail = head;
    int length = 1;
    while (tail->next) 
    {
        tail = tail->next;
        length++;
    }

    tail->next = head;
    head->prev = tail;

    k = k % length;
    if (k == 0) 
    {
        tail->next = nullptr;
        head->prev = nullptr;
        return head;
    }

    DNode<int>* newTail = head;
    for (int i = 0; i < length - k - 1; i++) 
    {
        newTail = newTail->next;
    }

    DNode<int>* newHead = newTail->next;

    newTail->next = nullptr;
    newHead->prev = nullptr;

    return newHead;
}

int main()
{
    DList<int> list;
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    DNode<int>* newHead = rotateRight(list.getNode(0), 23);
    list.head = newHead;
    list.printList();
}
