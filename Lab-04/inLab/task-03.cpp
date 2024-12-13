#include <iostream>
#include <string>
#include <stack>

using namespace std;

class TextEditor {
private:
    stack<string> undoStack; 
    stack<string> redoStack; 

public:
    void performAction(const string& action) 
    {
        undoStack.push(action); 
        while (!redoStack.empty()) 
        {
            redoStack.pop(); 
        }
    }

    void undoAction() 
    {
        if (!undoStack.empty()) 
        {
            string action = undoStack.top();
            undoStack.pop();
            redoStack.push(action); 
        }
    }

    void redoAction() 
    {
        if (!redoStack.empty()) 
        {
            string action = redoStack.top();
            redoStack.pop();
            undoStack.push(action); 
        }
    }

    void printActions() 
    {
        cout << "Undo Stack: ";
        stack<string> temp = undoStack;
        while (!temp.empty()) 
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;

        cout << "Redo Stack: ";
        temp = redoStack;
        while (!temp.empty()) 
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() 
{
    TextEditor editor;


    editor.performAction("A");
    editor.performAction("B");
    editor.performAction("C");
    
    editor.printActions();

    editor.undoAction();
    cout << "After undo:" << endl;
    editor.printActions();

    editor.redoAction();
    cout << "After redo:" << endl;
    editor.printActions();

    editor.undoAction();
    editor.undoAction();
    cout << "After two undos:" << endl;
    editor.printActions();
}