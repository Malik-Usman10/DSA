#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

struct Process 
{
    string id;
    int burstTime;
    
    Process(string pid = "", int burst = 0) : id(pid), burstTime(burst) {}
    
    friend ostream& operator<<(ostream& os, const Process& p) 
    {
        os << p.id << " (Burst Time: " << p.burstTime << ")";
        return os;
    }
};

class RoundRobinScheduler 
{
private:
    CircularLinkedList<Process> queue;
    int quantum;
    int roundNumber;

public:
    RoundRobinScheduler(int timeSlice) : quantum(timeSlice), roundNumber(1) {}

    void addProcess(string id, int burstTime) 
    {
        Process p(id, burstTime);
        queue.insertAtEnd(p);
    }

    void execute() 
    {
        while (true) 
        {
            cout << "\nRound " << roundNumber << ":" << endl;
            
            if (executeRound()) 
            {
                
                break;
            }
            
            roundNumber++;
        }
    }

private:
    bool executeRound() 
    {
        if (queue.isEmpty()) 
        {
            return false;
        }

        Node<Process>* current = queue.getHead();
        Node<Process>* prev = nullptr;
        bool processesRemaining = false;
        
        do {
            Process& p = current->info;
            
            int executeTime = min(quantum, p.burstTime);
            p.burstTime -= executeTime;
            
            cout << "Process " << p.id << " executes for " << executeTime << " units. ";
            
            if (p.burstTime <= 0) 
            {
                cout << "Process completed." << endl;
                
                if (prev == nullptr) 
                {
                    queue.removeHead();
                } 
                else 
                {
                    queue.removeAfter(prev);
                }
                
                if (queue.isEmpty()) 
                {
                    return false;
                }
                
                current = (prev == nullptr) ? queue.getHead() : prev->next;
            } 
            else 
            {
                cout << "Remaining time: " << p.burstTime << endl;
                prev = current;
                current = current->next;
                processesRemaining = true;
            }
            
        } while (current != queue.getHead());

        return processesRemaining;
    }
};

int main() 
{
    int numProcesses, quantum;
    
    cout << "Total Number of Processes: ";
    cin >> numProcesses;
    
    RoundRobinScheduler scheduler(quantum);
    
    for (int i = 1; i <= numProcesses; i++) 
    {
        int burstTime;
        cout << "Enter the burst time for P" << i + 1 << ": ";
        cin >> burstTime;
        scheduler.addProcess("P" + to_string(i), burstTime);
    }
    
    cout << "Enter the CPU time slice (Quantum): ";
    cin >> quantum;
    
    scheduler.execute();
    
    return 0;
}