#include <iostream>
#include "LinkedList.h"
using namespace std;

Node<int>* convertToCircular(LinkedList<int> list)
{
    Node<int> *temp = list.getHead();
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = list.getHead();
    return list.getHead();

}
Node<int>* convertCircularToLinear(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}

int main()
{
    LinkedList<int> list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.printList();

    Node<int> *circularHead = convertToCircular(list);
    list.printList();
    cout << circularHead->info << endl;
    Node<int> *LinearConversion = convertCircularToLinear(list.getHead());
    cout << LinearConversion->info << endl;
}
