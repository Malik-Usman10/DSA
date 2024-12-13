#include <iostream>
#include <string>
using namespace std;

string reverse(string s, int len) 
{
    if (len == 0) 
    {
        return s;
    } 
    else 
    {
        char temp = s[0];
        s[0] = s[len - 1];
        s[len - 1] = temp;
        return reverse(s, len - 1);
    }
}

int main() 
{
    string s = "hello";
    int len = s.length();
    s = reverse(s, len);
    cout << "Reversed string: " << s;
}