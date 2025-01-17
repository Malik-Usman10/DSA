#include <iostream>
using namespace std;

struct Node { 
    int value;      
    int height;    
    Node* left;     
    Node* right;
 
    Node(int key) : value(key), height(1), left(nullptr), right(nullptr) {} 
}; 
 
class AVLTree { 
private: 
    Node* root;

    int getHeight(Node* node) 
    {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalance(Node* node) 
    {
        return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insertHelper(Node* node, int key) 
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->value)
        {
            node->left = insertHelper(node->left, key);
        }
        else if (key > node->value)
            node->right = insertHelper(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->value)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->value)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* searchHelper(Node* node, int key) {
        if (node == nullptr || node->value == key)
            return node;

        if (key < node->value)
            return searchHelper(node->left, key);
        return searchHelper(node->right, key);
    }

    void displayHelper(Node* node) {
        if (node != nullptr) {
            displayHelper(node->left);
            cout << node->value << " ";
            displayHelper(node->right);
        }
    }

public: 
    AVLTree() : root(nullptr) {} 
 
    void insert(int key)
    {
        root = insertHelper(root, key);
    }                        
    void remove(int key)
    {

    }                      
    bool search(int key)
    {
        return searchHelper(root, key) != nullptr;
    }                      
    void display()
    {
        displayHelper(root);
        cout << endl;
    }                                
}; 

int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

}