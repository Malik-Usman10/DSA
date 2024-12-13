#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void KillWeaker(int* arr, int n) 
{

    stack<int> survivors; 

    for (int i = 0; i < n; i++) 
    {
        int currentHero = arr[i];

        while (!survivors.empty() && survivors.top() < currentHero) 
        {
            survivors.pop(); 
        }

        survivors.push(currentHero);
    }

    vector<int> result;
    while (!survivors.empty()) 
    {
        result.push_back(survivors.top());
        survivors.pop();
    }

    for (int i = result.size() - 1; i >= 0; i--) 
    {

    }
}
int main()
{
    arr = []
}