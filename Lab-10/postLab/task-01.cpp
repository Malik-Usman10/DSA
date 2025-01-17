#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        
        Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;
    
    int getHeight(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        return node->height;
    }
    
    int getBalance(Node* node) 
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    
    void updateHeight(Node* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    Node* rightRotate(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* leftRotate(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    Node* insertHelper(Node* node, const T& value) 
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }
        
        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }
        else
        {
            return node;  
        }
            
        updateHeight(node);
        
        int balance = getBalance(node);
        
        if (balance > 1 && value < node->left->data)
        {
            return rightRotate(node);
        }
            
        if (balance < -1 && value > node->right->data)
        {
            return leftRotate(node);
        }
            
        if (balance > 1 && value > node->left->data) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && value < node->right->data) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    Node* deleteHelper(Node* node, const T& value) 
    {
        if (node == nullptr) 
        {
            return nullptr;
        }
        
        if (value < node->data)
        {
            node->left = deleteHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteHelper(node->right, value);
        }
        else {
            if (node->left == nullptr || node->right == nullptr) 
            {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) 
                {
                    temp = node;
                    node = nullptr;
                } 
                else 
                {
                    *node = *temp;
                }
                delete temp;
            } 
            else 
            {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteHelper(node->right, temp->data);
            }
        }
        
        if (node == nullptr) 
        {
            return nullptr;
        }
        
        updateHeight(node);
        
        int balance = getBalance(node);
        
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }
            
        if (balance > 1 && getBalance(node->left) < 0) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        return node;
    }
    
    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
public:
    AVLTree() : root(nullptr) {}
    
    AVLTree(const AVLTree& other) 
    {
        root = copyHelper(other.root);
    }
    
    void insert(const T& value)
    {
        root = insertHelper(root, value);
    }
    
    void remove(const T& value) 
    {
        root = deleteHelper(root, value);
    }
    
    bool search(const T& value) const 
    {
        Node* current = root;
        while (current != nullptr) 
        {
            if (value == current->data)
            {
                return true;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }
};
int main() {
    AVLTree<int> tree;
    
    cout << "Inserting elements: 10, 20, 30, 40, 50" << endl;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    
    cout << "\nTesting search functionality:" << endl;
    cout << "Searching for 30: " << (tree.search(30) ? "Found" : "Not found") << endl;
    cout << "Searching for 25: " << (tree.search(25) ? "Found" : "Not found") << endl;
    
    cout << "\nRemoving element 30" << endl;
    tree.remove(30);
    cout << "Searching for 30 after removal: " << (tree.search(30) ? "Found" : "Not found") << endl;
    return 0;
}

