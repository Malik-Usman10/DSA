#include <cstdio>
#include <iostream>
#include <stack>
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

string infic_to_postFix(string infix) 
{
    stack<char> s;
    string postfix;
    
    for (int i = 0; i < infix.length(); i++) 
    {
        if (isalnum(infix[i])) 
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(') 
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (is_operator(infix[i])) 
        {
            while (!s.empty() && get_precedence(infix[i]) <= get_precedence(s.top())) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() 
{
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    
    string postfix = infic_to_postFix(infix);
    
    cout << "here is Infix expression: " << infix << endl;
    cout << "here is Postfix expression: " << postfix << endl;
    
    return 0;
}
