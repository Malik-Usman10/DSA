#include "queue.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FIFOPageReplacement 
{
private:
    MyLinearQueue<int> pageQueue;     
    vector<int> frameTable;   
    int capacity;                  
    int pageFaults;                
    int pageHits;       

public:
    FIFOPageReplacement(int frameSize) 
    {
        if (frameSize <= 0) 
        {
            throw invalid_argument("Frame size must be positive");
        }
        capacity = frameSize;
        pageFaults = 0;
        pageHits = 0;
    }

    bool isPagePresent(int page) 
    {
        for (int currentPage : frameTable) 
        {
            if (currentPage == page) 
            {
                return true;
            }
        }
        return false;
    }

    pair<bool, string> accessPage(int page) 
    {
        bool isHit = isPagePresent(page);
        string result = isHit ? "Page Hit" : "Page Fault";
        
        if (isHit) 
        {
            pageHits++;
        }
        else 
        {
            pageFaults++;
            cout << "Page Fault!" << endl;

            if (frameTable.size() < capacity) 
            {
                frameTable.push_back(page);
                pageQueue.enqueue(page);  
            }
            else 
            {
                int pageToRemove = pageQueue.getFront();
                pageQueue.dequeue();
                
                for (size_t i = 0; i < frameTable.size(); i++) 
                {
                    if (frameTable[i] == pageToRemove) 
                    {
                        frameTable[i] = page;
                        break;
                    }
                }
                pageQueue.enqueue(page);  
            }
        }

        string memoryState = "Current memory state: ";
        for (int p : frameTable) 
        {
            memoryState += to_string(p) + " ";
        }
        
        return {isHit, result + "\n" + memoryState};
    }

    void displayState() const 
    {
        cout << "Current frame table state: ";
        if (frameTable.empty()) 
        {
            cout << "Empty";
        }
        else 
        {
            for (int page : frameTable) 
            {
                cout << page << " ";
            }
        }
        cout << endl;
    }


    void displayStatistics() const 
    {
        cout << "\n=== Page Replacement Statistics ===" << endl;
        cout << "Total page faults: " << pageFaults << endl;
        cout << "Total page hits: " << pageHits << endl;
        int totalRequests = pageFaults + pageHits;
        if (totalRequests > 0) 
        {
            double faultRate = (static_cast<double>(pageFaults) / totalRequests) * 100;
            double hitRate = (static_cast<double>(pageHits) / totalRequests) * 100;
            cout << "Fault rate: " << faultRate << "%" << endl;
            cout << "Hit rate: " << hitRate << "%" << endl;
        }
    }
};

int main() 
{
    try {
        int frameSize;
        cout << "Enter the number of frames: ";
        if (!(cin >> frameSize)) 
        {
            throw invalid_argument("Invalid input for frame size");
        }

        FIFOPageReplacement fifo(frameSize);
        
        string input;
        while (true) 
        {
            cout << "Enter a page number (or 'quit' to end): ";
            cin >> input;
            if (input == "quit") break;
            
            int page;
            try {
                page = stoi(input);
                if (page < 0) throw invalid_argument("Page number must be non-negative");
                auto [isHit, message] = fifo.accessPage(page);
                cout << message << endl;
            } 
            catch (const invalid_argument& e) 
            {
                cout << "Invalid input. Please enter a non-negative integer or 'quit'." << endl;
            }
        }

        fifo.displayStatistics();
    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
