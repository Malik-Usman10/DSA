#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node* root;

    Node* insertHelper(Node* node, int value)
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }

        if (value < node -> data) 
        {
            node -> left = insertHelper(node -> left, value);
        }
        else if (value > node -> data) 
        {
            node -> right = insertHelper(node -> right, value);
        }
        return node;
    }
public:
    BST() : root(nullptr) {};

    void insert(int value) 
    {
        root = insertHelper(root, value);
    }
};


bool Check(Node* root1, Node* root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    
    if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    
    return (root1->data == root2->data) && 
           Check(root1->left, root2->left) && 
           Check(root1->right, root2->right);
}

int main()
{
    BST treeOne;
    treeOne.insert(1);
    treeOne.insert(2);
    treeOne.insert(3);
    treeOne.insert(4);
    treeOne.insert(5);

    BST treeTwo;
    treeOne.insert(1);
    treeOne.insert(2);
    treeOne.insert(3);
    treeOne.insert(4);
    treeOne.insert(5);

    Check(treeOne, treeTwo);
}