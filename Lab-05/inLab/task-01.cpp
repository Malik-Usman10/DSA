#include <iostream>
#include <limits>
using namespace std;

template <class T> class PriorityQueue 
{
private:
  T *data;
  int *priorities;
  int capacity;
  int currentSize;

public:
  PriorityQueue(int size = 100) 
  {
    capacity = size;
    currentSize = 0;
    data = new T[capacity];
    priorities = new int[capacity];
  }


  ~PriorityQueue() 
  {
    delete[] data;
    delete[] priorities;
  }

  void enqueue(const T &element, int priority) 
  {
    if (isFull()) 
    {
      cout << "Queue is full!" << endl;
      return;
    }

    int pos = currentSize;
    while (pos > 0 && priorities[pos - 1] > priority) 
    {
      data[pos] = data[pos - 1];
      priorities[pos] = priorities[pos - 1];
      pos--;
    }

    data[pos] = element;
    priorities[pos] = priority;
    currentSize++;
  }

  T dequeue() 
  {
    if (isEmpty()) 
    {
      throw runtime_error("Queue is empty!");
    }

    T element = data[0];

    for (int i = 0; i < currentSize - 1; i++) 
    {
      data[i] = data[i + 1];
      priorities[i] = priorities[i + 1];
    }

    currentSize--;
    return element;
  }

  bool isEmpty() const 
  { 
    return currentSize == 0;
  }

  bool isFull() const 
  { 
    return currentSize == capacity; 
  }

  int size() const 
  { 
    return currentSize; 
  }

  void display() const 
  {
    if (isEmpty()) 
    {
      cout << "Queue is empty!" << endl;
      return;
    }
    cout << "\nCurrent Queue (Element, Priority):" << endl;

    for (int i = 0; i < currentSize; i++) 
    {
      cout << "(" << data[i] << ", " << priorities[i] << ") ";
    }
    cout << endl;
  }
};
void clearInputBuffer() 
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() 
{
  int capacity;

  do 
  {
    cout << "Enter the capacity of priority queue (1-100): ";
    if (!(cin >> capacity) || capacity <= 0 || capacity > 100) 
    {
      cout << "Invalid capacity! Please enter a number between 1 and 100."
           << endl;
      clearInputBuffer();
      capacity = 0;
    }
  } while (capacity <= 0 || capacity > 100);

  PriorityQueue<int> pq(capacity);

  int choice;
  do {
    cout << "\n=== Priority Queue Operations ===" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display Queue" << endl;
    cout << "4. Check Size" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";

    if (!(cin >> choice))
    {
      cout << "Invalid input! Please enter a number." << endl;
      clearInputBuffer();
      continue;
    }

    switch (choice) 
    {
    case 1: 
    { 
        int element, priority;
        
        cout << "Enter element to enqueue: ";
        if (!(cin >> element)) 
        {
            cout << "Invalid element! Please enter a number." << endl;
            clearInputBuffer();
            break;
        }
        
        cout << "Enter priority (lower number = higher priority): ";
        if (!(cin >> priority)) 
        {
            cout << "Invalid priority! Please enter a number." << endl;
            clearInputBuffer();
            break;
        }
        
        try {
            pq.enqueue(element, priority);
            cout << "Element " << element << " with priority " << priority << " enqueued successfully!" << endl;
            pq.display();
        }
        catch (const runtime_error& e) 
        {
            cout << "Error: " << e.what() << endl;
        }
        break;
}

    case 2: { 
      try 
      {
        int element = pq.dequeue();
        cout << "Dequeued element: " << element << endl;
        pq.display();
      } 
      catch (const runtime_error &e) 
      {
        cout << "Error: " << e.what() << endl;
      }
      break;
    }

    case 3: 
      pq.display();
      break;

    case 4:
      cout << "Current size of queue: " << pq.size() << endl;
      cout << "Remaining capacity: " << capacity - pq.size() << endl;
      break;

    case 5: 
      cout << "Exiting program..." << endl;
      break;

    default:
      cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
    }

  } while (choice != 5);

  return 0;
}