#include <iostream>
#include <stack>
using namespace std;

bool blanced(const string& str) 
{
    stack<char> stack;

    for (char c : str) 
    {
        if (c == '(') 
        {
            stack.push(c);
        } 
        else if (c == ')') 
        {
            if (stack.empty()) 
            {
                return false; 
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    string equationOne = "))";
    // string equationTwo = "((a + b)) * (c - d))";
    // string equationThree = "((a + b) * (c - d)";
    // string equationFour = "(a + b) * (c - d)))";

    // cout << blanced(equationOne) << endl;
    // cout << blanced(equationTwo) << endl; 
    // cout << blanced(equationThree) << endl; 
    cout << blanced(equationOne) << endl; 
}
