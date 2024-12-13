#include"doubleLinkedList.h"
using namespace std;

DNode<int>* doubleIt(DNode<int>* head)
{
    if (head == nullptr) 
    {
        return nullptr;
    }
    
    int num = 0;
    DNode<int>* temp = head;
    while (temp != nullptr)  
    {
        num = num * 10 + temp->info;
        temp = temp->next;
    }
    
    num = num * 2; 
    
    temp = head;
    int divisor = 1;
    int numCopy = num; 
    while (numCopy >= 10) 
    {
        divisor = divisor * 10;
        numCopy /= 10; 
    }
    
    while (temp != nullptr && divisor > 0) 
    {
        temp->info = (num / divisor) % 10; 
        divisor /= 10; 
        temp = temp->next;
    }
    return head;
}

int main()
{
    DList<int> list;
    list.insertAtHead(0);
    list.insertAtHead(0);
    list.insertAtHead(9);

    doubleIt(list.getNode(0));
    list.printList();
}





























//Given a singly lInkedlist implement a function that double the 
//value of non negative integers.
//Each node in the list contains a single digit of the Numebr
//Return the head of the linked  list after doubling it
//Example input head = [1,8,9]
//output: [3,7,8]  
//189*2 = 378