#include "doubleLinkedList.h"
#include <vector>
using namespace std;

vector<int> DLLToArray(DNode<int>* node)
{
    vector<int> result;
    
    DNode<int>* current = node;
    while (current->prev != nullptr) 
    {
        current = current->prev;
    }
    
    while (current != nullptr) 
    {
        result.push_back(current->info);
        current = current->next;
    }
    
    return result;
}

int main()
{
    DList<int> list;
    list.insertAtHead(9);
    list.insertAtHead(8);
    list.insertAtHead(7);
    list.insertAtHead(6);
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(1);


    vector<int> arr = DLLToArray(list.getNode(1));
    for(int i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

































