#include "doubleLinkedList.h"
#include <iostream>
using namespace std;

void pairSum(DNode<int>* head, int k)
{
    if (!head) 
    {
        return;
    }

    DNode<int>* start = head;
    DNode<int>* end = head;
    
    while (end->next != nullptr) 
    {
        end = end->next;
    }
    while (start != end && end->next != start) 
    {
        int sum = start->info + end->info;
        
        if (sum == k) 
        {
            cout << "(" << start->info << "," << end->info << ") ";
            start = start->next;
            end = end->prev;
        }
        else if (sum < k) 
        {
            start = start->next;
        }
        else 
        {
            end = end->prev;
        }
    }
    cout << endl;
}


int main()
{
    DList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(8);
    list.insertAtHead(6);
    list.insertAtHead(4);
    list.insertAtHead(2);
    list.insertAtHead(0);
    
    pairSum(list.getNode(0), 10);

}























