#include "circularQueue.h"
#include "myQueue.h"
#include <iostream>
#include <limits>
using namespace std;

void clearInputBuffer() 
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() 
{
  cout << "\nQueue Operations Menu:" << endl;
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. Peek Front" << endl;
  cout << "4. Check Size" << endl;
  cout << "5. Check if Empty" << endl;
  cout << "6. Check if Full" << endl;
  cout << "7. Exit" << endl;
  cout << "Enter your choice: ";
}

void operateLinearQueue() 
{
  cout << "\n=== Linear Queue Operations ===" << endl;

  int initialCapacity;
  while (true) 
  {
    cout << "Enter initial capacity for Linear Queue: ";
    if (cin >> initialCapacity && initialCapacity > 0) 
    {
      break;
    }
    cout << "Please enter a valid positive number." << endl;
    clearInputBuffer();
  }

  MyLinearQueue<int> queue;

  while (true)
  {
    displayMenu();

    int choice;
    if (!(cin >> choice)) 
    {
      cout << "Invalid input. Please enter a number." << endl;
      clearInputBuffer();
      continue;
    }

    try {
      switch (choice) 
      {
      case 1: {
        cout << "Enter element to enqueue: ";
        int element;
        if (cin >> element) 
        {
          queue.enqueue(element);
          cout << "Enqueued " << element << " successfully!" << endl;
        } 
        else 
        {
          cout << "Invalid input." << endl;
          clearInputBuffer();
        }
        break;
      }

      case 2: {
        if (!queue.isEmpty()) 
        {
          int element = queue.dequeue();
          cout << "Dequeued element: " << element << endl;
        } 
        else 
        {
          cout << "Queue is empty!" << endl;
        }
        break;
      }

      case 3: 
      {
        if (!queue.isEmpty()) 
        {
          cout << "Front element: " << queue.getFront() << endl;
        } 
        else 
        {
          cout << "Queue is empty!" << endl;
        }
        break;
      }

      case 4: 
        cout << "Current queue size: " << queue.size() << endl;
        break;

      case 5: 
        cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty")
             << endl;
        break;

      case 6: 
        cout << "Linear queue grows dynamically, it's never full!" << endl;
        break;

      case 7: 
        cout << "Exiting Linear Queue operations." << endl;
        return;

      default:
        cout << "Invalid choice. Please try again." << endl;
      }
    }
    catch (const runtime_error &e) 
    {
      cout << "Operation failed: " << e.what() << endl;
    }
  }
}

void operateCircularQueue() 
{
  cout << "\n=== Circular Queue Operations ===" << endl;


  int size;
  while (true) 
  {
    cout << "Enter size for Circular Queue: ";
    if (cin >> size && size > 0)
    {
      break;
    }
    cout << "Please enter a valid positive number." << endl;
    clearInputBuffer();
  }

  CircularQueue<int> queue(size);
  cout << "Created Circular Queue of size " << size << endl;

  while (true) 
  {
    displayMenu();

    int choice;
    if (!(cin >> choice)) 
    {
      cout << "Invalid input. Please enter a number." << endl;
      clearInputBuffer();
      continue;
    }

    try {
      switch (choice) 
      {
      case 1: { 
        if (queue.isFull()) 
        {
          cout << "Queue is full! Cannot enqueue." << endl;
          break;
        }
        cout << "Enter element to enqueue: ";
        int element;
        if (cin >> element) 
        {
          queue.enqueue(element);
          cout << "Enqueued " << element << " successfully!" << endl;
        } 
        else 
        {
          cout << "Invalid input." << endl;
          clearInputBuffer();
        }
        break;
      }

      case 2: { 
        if (!queue.isEmpty()) 
        {
          int element = queue.dequeue();
          cout << "Dequeued element: " << element << endl;
        } 
        else 
        {
          cout << "Queue is empty!" << endl;
        }
        break;
      }

      case 3: { 
        if (!queue.isEmpty()) 
        {
          cout << "Front element: " << queue.peek() << endl;
        } 
        else 
        {
          cout << "Queue is empty!" << endl;
        }
        break;
      }

      case 4: 
        cout << "Current queue size: " << queue.size() << endl;
        break;

      case 5: 
        cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty")
             << endl;
        break;

      case 6: 
        cout << "Queue is " << (queue.isFull() ? "full" : "not full") << endl;
        break;

      case 7: 
        cout << "Exiting Circular Queue operations." << endl;
        return;

      default:
        cout << "Invalid choice. Please try again." << endl;
      }
    } 
    catch (const runtime_error &e) 
    {
      cout << "Operation failed: " << e.what() << endl;
    }
  }
}

int main() 
{
  while (true) 
  {
    cout << "\n=== Queue Implementation Menu ===" << endl;
    cout << "1. Linear Queue" << endl;
    cout << "2. Circular Queue" << endl;
    cout << "3. Exit Program" << endl;
    cout << "Enter your choice: ";

    int choice;
    if (!(cin >> choice)) 
    {
      cout << "Invalid input. Please enter a number." << endl;
      clearInputBuffer();
      continue;
    }

    switch (choice) 
    {
    case 1:
      operateLinearQueue();
      break;

    case 2:
      operateCircularQueue();
      break;

    case 3:
      cout << "Thank you for using the Queue Program!" << endl;
      return 0;

    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}