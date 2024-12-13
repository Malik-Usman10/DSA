#include <iostream>
#include <unordered_map>
#include "myQueue.h"

using namespace std;

template<typename T>
void displayCache(MyLinearQueue<T>& cache) 
{
    int size = cache.size();
    MyLinearQueue<T> tempCache = cache; 

    cout << "Cache State: [ ";
    while (!tempCache.isEmpty()) 
    {
        cout << tempCache.dequeue() << " "; 
    }
    cout << "]" << endl;
}

void handlePageHit(MyLinearQueue<int>& cache, int page) 
{
    MyLinearQueue<int> tempQueue;
    bool found = false;

    while (!cache.isEmpty()) 
    {
        int currentPage = cache.dequeue();
        if (currentPage == page && !found) 
        {
            found = true;
        } 
        else 
        {
            tempQueue.enqueue(currentPage);
        }
    }

    cache.enqueueFront(page);
    while (!tempQueue.isEmpty()) 
    {
        cache.enqueue(tempQueue.dequeue());
    }
}

int main() 
{
    int cacheSize;
    cout << "Enter cache size: ";
    cin >> cacheSize;

    MyLinearQueue<int> cache;
    unordered_map<int, bool> pageMap;

    string input;
    cout << "Enter page requests followed by 'quit' to stop: " << endl;

    while (true) 
    {
        cin >> input;

        if (input == "quit") 
        {
            break;
        }

        int page = stoi(input);

        if (pageMap[page]) 
        {
            cout << "Page Hit: " << page << endl;
            handlePageHit(cache, page);
        }
        else 
        {
            cout << "Page Fault: " << page << endl;

            if (cache.size() == cacheSize) 
            {
                int leastUsed = cache.dequeueRear();  
                pageMap[leastUsed] = false; 
            }

            cache.enqueueFront(page);
            pageMap[page] = true; 
        }

        displayCache(cache);
    }
    cout << "Final Cache State: ";
    displayCache(cache);
}
