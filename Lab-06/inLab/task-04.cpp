#include "LinkedList.h"
using namespace std;

void deleteNode(Node<int> *node)
{
    Node<int> *temp = node->next;
    node->info = temp->info;
    node->next = temp->next;
    delete temp;
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
    deleteNode(list.search(3));
    list.printList();
}