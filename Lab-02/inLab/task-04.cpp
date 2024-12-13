#include<iostream>
using namespace std;

void func(string s,int len) 
{
    if(len == 0)
    {                                                                    // 3... 000 111
        cout << s << endl; 
        return;     
    }
    func(s + '0', len-1);
    func(s + '1', len-1);
}

int main() {
    int nBit;
    cout << "Enter the Number of BITS: " << endl;
    cin >> nBit;
    func("", nBit);
}




