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

    Node* findMin(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        while (node -> left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }
    
    Node* copyHelper(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        } 
        Node* newNode = new Node(node->data);
        newNode->left = copyHelper(node->left);
        newNode->right = copyHelper(node->right);
        return newNode;
    }

    void inOrderHelper(Node* node)
    {
        if (node == nullptr) 
        {
            return;
        }
        inOrderHelper(node -> left);
        cout << node -> data << " ";
        inOrderHelper(node -> right);
    }

    void preOrderHelper(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }
        cout << node -> data << " ";
        preOrderHelper(node -> left);
        preOrderHelper(node -> right);

    }
public:
    BST() : root(nullptr) {};
    BST(const BST& other)
    {
        root =  copyHelper(other.root);
    }

    void insert(int value) 
    {
        root = insertHelper(root, value);
    }
    
    void remove(int value) 
    {
        root = deleteHelper(root, value);
    }
    
    bool searchDFS(int value) 
    {
        return searchDFS(root, value) != nullptr;
    }
    int findMin() 
    {
        Node* minNode = findMin(root);
        if (minNode == nullptr) 
        {
            throw runtime_error("Tree is empty");
        }
        return minNode->data;
    }
    
    void inOrder() 
    {
        inOrderHelper(root);
        cout << endl;
    }
    
    void preOrder() 
    {
        preOrderHelper(root);
        cout << endl;
    }
    
    void postOrder() 
    {
        postOrderHelper(root);
        cout << endl;
    } 
};

int main()
{
    BST tree;
        
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    tree.insert(80);
    tree.insert(40);
    tree.insert(15);
    tree.insert(70);
    
    cout << "Original Tree Traversals:" << endl;
    cout << "In-order: ";
    tree.inOrder();
    cout << "Pre-order: ";
    tree.preOrder();
    cout << "Post-order: ";
    tree.postOrder();

    BST treeCopy = tree;
    cout << "\nCopied Tree In-order: ";
    treeCopy.inOrder();

    cout << "Searching Value 15" << endl;
    if (tree.searchDFS(15) == true) 
    {
        cout << "Found " << endl;
    }
    else 
    {
        cout << "Value Not found" << endl;
    }


    cout << "Minimum value: " << tree.findMin() << endl;

    cout << "\nDeleting 30..." << endl;
    tree.remove(30);
    cout << "In-order after deletion: ";
    tree.inOrder();



    
    
}
