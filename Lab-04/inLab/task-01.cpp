#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isPalindrome(const string& str)
{
    Stack s;
    for(char c : str)
    {
        s.push(c);
    }
    string reversedStr = "";
    while (!s.isEmpty())
    {
        reversedStr += s.top();
        s.pop();
    }
    return str == reversedStr;

}

int main()
{
    string input;
    cout << "Enter the String You want to check: ";
    getline(cin, input);
    
    string str{input};
    if (isPalindrome(str))
    {
        cout << str << " is palindrome " << endl;
    }
    else
    {
        cout << str << " is not palindrome " << endl;
    }
}