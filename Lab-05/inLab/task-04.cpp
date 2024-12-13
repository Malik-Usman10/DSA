#include "queue.h"
#include <iostream>
#include <string>

void generateBinaryNumbers(int N) 
{
    MyLinearQueue<string> queue;
    
    queue.enqueue("1");

    for (int i = 1; i <= N; i++) 
    {
        string s1 = queue.dequeue();
        
        cout << s1 << " ";
        
        // Append "0" to s1 and enqueue it
        string s2 = s1 + "0";
        queue.enqueue(s2);
        
        s2 = s1 + "1";
        queue.enqueue(s2);
    }
    cout << endl;
}

int main() 
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    cout << "Binary numbers from 1 to " << N << " are:" << endl;
    generateBinaryNumbers(N);
    
    return 0;
}