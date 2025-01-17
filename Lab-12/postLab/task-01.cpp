#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    string *table;         
    bool *isOccupied;      
    int size;         

    int hashFunction(const string &key) 
    {
        int hash = 0;
        for (char ch : key) 
        {
            hash += ch;
        }
        return hash % size;
    }

public:
    HashTable(int tableSize) 
    {
        size = tableSize;
        table = new string[size];
        isOccupied = new bool[size];
        for (int i = 0; i < size; i++) 
        {
            table[i] = "EMPTY";
            isOccupied[i] = false;
        }
    }

    ~HashTable() 
    {
        delete[] table;
        delete[] isOccupied;
    }

    bool insert(const string &name) 
    {
        int index = hashFunction(name);
        int traversed = 0;

        while (isOccupied[index] && traversed < size) 
        {
            cout << "Index " << index << " is occupied. Probing...\n";
            index = (index + 1) % size;
            traversed++;
        }

        if (traversed == size) 
        {
            cout << "Hash table is full. Cannot insert \"" << name << "\".\n";
            return false;
        }

        table[index] = name;
        isOccupied[index] = true;
        cout << "Inserted \"" << name << "\" at index " << index << ".\n";
        return true;
    }

    bool search(const string &name) 
    {
        int index = hashFunction(name);
        int traversed = 0;

        while (isOccupied[index] && traversed < size) 
        {
            cout << "Checking index " << index << ".\n";
            if (table[index] == name) 
            {
                cout << "\"" << name << "\" found at index " << index << ".\n";
                return true;
            }
            index = (index + 1) % size;
            traversed++;
        }

        cout << "\"" << name << "\" not found in the hash table.\n";
        return false;
    }

    void display() 
    {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i < size; i++) 
        {
            cout << "Index " << i << ": " << table[i] << "\n";
        }
    }

    bool remove(const string &name) 
    {
        int index = hashFunction(name);
        int traversed = 0;

        while (isOccupied[index] && traversed < size) 
        {
            if (table[index] == name) 
            {
                cout << "Removing \"" << name << "\" from index " << index << ".\n";
                table[index] = "EMPTY";
                isOccupied[index] = false;
                return true;
            }
            index = (index + 1) % size;
            traversed++;
        }

        cout << "\"" << name << "\" not found. Cannot remove.\n";
        return false;
    }
};

int main() 
{
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    while (tableSize <= 0) 
    {
        cout << "Invalid size. Please enter a positive integer: ";
        cin >> tableSize;
    }

    HashTable hashTable(tableSize);

    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Remove\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name to insert: ";
            cin >> name;
            hashTable.insert(name);
            break;
        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            hashTable.search(name);
            break;
        case 3:
            hashTable.display();
            break;
        case 4:
            cout << "Enter name to remove: ";
            cin >> name;
            hashTable.remove(name);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}