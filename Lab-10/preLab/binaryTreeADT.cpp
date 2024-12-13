#include <iostream>
#include <exception>
using namespace std;
template <typename T>
class ArrayBinaryTree {
private:
    T* tree;
    int capacity;
    int size;
    
    int findIndex(T key) const 
    {
        for (int i = 0; i < size; i++) 
        {
            if (tree[i] == key) return i;
        }
        return -1;
    }
    
    void resize() 
    {
        capacity *= 2;
        T* newTree = new T[capacity];
        for (int i = 0; i < size; i++) 
        {
            newTree[i] = tree[i];
        }
        delete[] tree;
        tree = newTree;
    }

public:
    ArrayBinaryTree(int initialCapacity = 10) 
    {
        capacity = initialCapacity;
        size = 0;
        tree = new T[capacity];
    }
    
    ~ArrayBinaryTree() 
    {
        delete[] tree;
    }
    
    ArrayBinaryTree(const ArrayBinaryTree& other) 
    {
        capacity = other.capacity;
        size = other.size;
        tree = new T[capacity];
        for (int i = 0; i < size; i++) 
        {
            tree[i] = other.tree[i];
        }
    }
    
    void setLeftChild(T parentKey, T value) 
    {
        int parentIndex = findIndex(parentKey);
        if (parentIndex == -1) 
        {
            throw runtime_error("Parent key not found");
        }
        
        int leftChildIndex = 2 * parentIndex + 1;
        if (leftChildIndex >= capacity) 
        {
            resize();
        }
        
        if (leftChildIndex >= size) 
        {
            size = leftChildIndex + 1;
        }
        tree[leftChildIndex] = value;
    }
    
    void setRightChild(T parentKey, T value) 
    {
        int parentIndex = findIndex(parentKey);
        if (parentIndex == -1) 
        {
            throw runtime_error("Parent key not found");
        }
        
        int rightChildIndex = 2 * parentIndex + 2;
        if (rightChildIndex >= capacity) 
        {
            resize();
        }
        
        if (rightChildIndex >= size) 
        {
            size = rightChildIndex + 1;
        }
        tree[rightChildIndex] = value;
    }
    
    T getParent(T key) 
    {
        int index = findIndex(key);
        if (index <= 0) 
        {
            throw runtime_error("Node not found or is root");
        }
        
        int parentIndex = (index - 1) / 2;
        return tree[parentIndex];
    }
    
    void setRoot(T value) 
    {
        tree[0] = value;
        if (size == 0) size = 1;
    }
};

int main() 
{
    try {
        ArrayBinaryTree<int> tree;
        
        tree.setRoot(0);
        
        tree.setLeftChild(0, 2);    
        tree.setRightChild(0, 3);   
        
        tree.setLeftChild(2, 4);    
        tree.setRightChild(2, 5);  
        tree.setLeftChild(3, 6);   
        tree.setRightChild(3, 7);   
        
        cout << "Parent of 4: " << tree.getParent(4) << " (should be 2)" << endl;
        cout << "Parent of 5: " << tree.getParent(5) << " (should be 2)" << endl;
        cout << "Parent of 2: " << tree.getParent(2) << " (should be 0)" << endl;
        cout << "Parent of 3: " << tree.getParent(3) << " (should be 0)" << endl;
        
        ArrayBinaryTree<int> treeCopy = tree;
        cout << "Copy test - Parent of 4 in copied tree: " << treeCopy.getParent(4) << endl;
        
        try {
            tree.getParent(0);  
        } catch (const runtime_error& e) 
        {
            cout << "Expected error caught: " << e.what() << endl;
        }
        
        try {
            tree.setLeftChild(99, 100);
        } catch (const runtime_error& e) 
        {
            cout << "Expected error caught: " << e.what() << endl;
        }
        
    } catch (const exception& e) 
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

