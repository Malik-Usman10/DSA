#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

void reverseWords(string& str) 
{
    Stack charStack; 
    string result = ""; 

    for (char ch : str) 
    {
        if (ch == ' ') 
        {
            while (!charStack.isEmpty()) 
            {
                result += charStack.top();
                charStack.pop();
            }
            result += ' '; 
        } 
        else 
        {
            charStack.push(ch); 
        }
    }

    while (!charStack.isEmpty()) 
    {
        result += charStack.top();
        charStack.pop();
    }

    str = result; 
}

int main() 
{
    string str = "                                   DSA";
    reverseWords(str);
    cout << str << endl; 
}