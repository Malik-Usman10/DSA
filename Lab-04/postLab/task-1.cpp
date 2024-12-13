#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool is_operator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int get_precedence(char c) 
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infix_to_prefix(string infix) 
{
    reverse(infix.begin(), infix.end());
    
    for (int i = 0; i < infix.length(); i++) 
    {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    stack<char> s;
    string prefix;
    
    for (int i = 0; i < infix.length(); i++) 
    {
        if (isalnum(infix[i])) 
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(') 
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(') 
            {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty()) 
            {
                s.pop();
            }
        }
        else if (is_operator(infix[i])) 
        {
            while (!s.empty() && get_precedence(infix[i]) <= get_precedence(s.top())) 
            {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    
    while (!s.empty()) 
    {
        prefix += s.top();
        s.pop();
    }
    
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() 
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    
    string prefix = infix_to_prefix(infix);
    
    cout << "HEre are the Infix expression: " << infix << endl;
    cout << "HEre are ther Prefix expression: " << prefix << endl;
    
    return 0;
}
