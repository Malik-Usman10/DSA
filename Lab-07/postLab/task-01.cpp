#include <iostream>
#include <cstdint>
using namespace std;

class XORList 
{
private:
    struct Node 
    {
        int data;
        Node* npx;  
    };
    Node* head;
    Node* tail;

    Node* XOR(Node* a, Node* b) 
    {
        return reinterpret_cast<Node*>(
            reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b)
        );
    }
public:
    XORList() : head(nullptr), tail(nullptr) {}
    ~XORList() 
    {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next;

        while (curr != nullptr) 
        {
            next = XOR(prev, curr->npx);
            delete curr;
            prev = curr;
            curr = next;
        }
    }
    void insertAtHead(int val) 
    {
        Node* newNode = new Node{val, head};
        if (head == nullptr) 
        {
            tail = newNode;
        } 
        else 
        {
            head->npx = XOR(newNode, XOR(nullptr, head->npx));
        }
        head = newNode;
    }
    void insertAtTail(int val) 
    {
        Node* newNode = new Node{val, tail};
        if (tail == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            tail->npx = XOR(XOR(tail->npx, nullptr), newNode);
        }
        tail = newNode;
    }
    int deleteAtHead() 
    {
        if (head == nullptr) 
        {
            throw runtime_error("List is empty");
        }
        Node* temp = head;
        int val = temp->data;
        head = XOR(nullptr, head->npx);
        if (head != nullptr) 
        {
            head->npx = XOR(nullptr, XOR(temp, head->npx));
        } 
        else 
        {
            tail = nullptr;
        }
        delete temp;
        return val;
    }
    int deleteAtTail() 
    {
        if (tail == nullptr) 
        {
            throw runtime_error("List is empty");
        }
        Node* temp = tail;
        int val = temp->data;

        tail = XOR(tail->npx, nullptr);
        if (tail != nullptr) 
        {
            tail->npx = XOR(XOR(tail->npx, temp), nullptr);
        } 
        else 
        {
            head = nullptr;
        }
        delete temp;
        return val;
    }
    void printList() 
    {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next;

        while (curr != nullptr) 
        {
            cout << curr->data << " ";
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        cout << endl;
    }
};
int main() 
{
    XORList list;

    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    
    cout << "List after inserting 1, 2, 3 at head: ";
    list.printList();  


    list.insertAtTail(4);
    list.insertAtTail(5);
    
    cout << "List after inserting 4, 5 at tail: ";
    list.printList();  

    cout << "Deleted from head: " << list.deleteAtHead() << endl;
    cout << "List after deleting from head: ";
    list.printList();  

    cout << "Deleted from tail: " << list.deleteAtTail() << endl;
    cout << "List after deleting from tail: ";
    list.printList();  

    while (true) 
    {
        try {
            list.deleteAtHead();
            cout << "Current list: ";
            list.printList();
        } 
        catch (runtime_error& e) 
        {
            cout << "List is now empty" << endl;
            break;
        }
    }
}
