#include "LinkedList.h"
#include <iostream>
using namespace std;


int main() 
{
    LinkedList<int> list;

    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    cout << "Original list: ";
    list.printList();

    
    list.reverseList();

    cout << "Reversed list: ";
    list.printList();
    return 0;
}