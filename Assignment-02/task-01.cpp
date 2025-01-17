#include <iostream>
#include <string>

using namespace std;
 
struct ProjectNode
{
    string projectName;
    string projectCode;
    bool isCompleted;
    ProjectNode *next;

    ProjectNode(const string &name, const string &code, bool status): projectName(name), projectCode(code), isCompleted(status), next(nullptr) {}
};

struct EmployeeData
{
    string name;
    string employeeID;
    ProjectNode *head;

    EmployeeData(const string &name, const string &id): name(name), employeeID(id), head(nullptr) {}
};

struct EmployeeNode
{
    EmployeeData data;
    EmployeeNode *prev;
    EmployeeNode *next;

    EmployeeNode(const string &id, const string &name): data(name, id), prev(nullptr), next(nullptr) {}
};

class EmployeeList
{
private:
    EmployeeNode *head;

public:
    EmployeeList() : head(nullptr) {}

    ~EmployeeList()
    {
        while (head)
        {
            removeEmployee(head->data.employeeID);
        }
    }

    bool addEmployee(const string &employeeID, const string &name)
    {
        if (findEmployee(employeeID))
        {
            return false;
        }

        EmployeeNode *newNode = new EmployeeNode(employeeID, name);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            EmployeeNode *current = head;
            EmployeeNode *prev = nullptr;

            while (current && current->data.employeeID < employeeID)
            {
                prev = current;
                current = current->next;
            }

            if (!prev)
            { 
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else
            {
                newNode->next = current;
                newNode->prev = prev;
                prev->next = newNode;
                if (current)
                    current->prev = newNode;
            }
        }
        return true;
    }

    bool addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted)
    {
        EmployeeNode *employee = findEmployee(employeeID);
        if (!employee)
        {
            return false;
        }

        ProjectNode *project = employee->data.head;
        while (project)
        {
            if (project->projectCode == projectCode)
            {
                return false; 
            }
            project = project->next;
        }

        ProjectNode *newProject = new ProjectNode(projectName, projectCode, isCompleted);
        newProject->next = employee->data.head;
        employee->data.head = newProject;

        return true;
    }

    bool removeEmployee(const string &employeeID)
    {
        EmployeeNode *employee = findEmployee(employeeID);
        if (!employee)
        {
            return false;
        }

        ProjectNode *project = employee->data.head;
        while (project)
        {
            ProjectNode *temp = project;
            project = project->next;
            delete temp;
        }

        if (employee->prev)
        {
           employee->prev->next = employee->next;
        }    
        if (employee->next)
        {
            employee->next->prev = employee->prev;
        }
        if (employee == head)
        {
            head = employee->next;
        }
        delete employee;
        return true;
    }

    void updateEmployee(const string &employeeID, const string &newProjectName, bool isCompleted)
    {
        EmployeeNode *employee = findEmployee(employeeID);
        if (!employee)
        {
            return;
        }

        ProjectNode *newProject = new ProjectNode(newProjectName, "AUTO" + to_string(rand() % 1000), isCompleted);
        newProject->next = employee->data.head;
        employee->data.head = newProject;
    }

    void displayEmployee(const string &employeeID)
    {
        EmployeeNode *employee = findEmployee(employeeID);
        if (!employee)
        {
            cout << "Employee not found.\n";
            return;
        }

        cout << "Employee ID: " << employee->data.employeeID << "\n";
        cout << "Name: " << employee->data.name << "\n";
        cout << "Projects:\n";
        ProjectNode *project = employee->data.head;
        while (project)
        {
            cout << "  - Project: " << project->projectName
                 << ", Code: " << project->projectCode
                 << ", Completed: " << (project->isCompleted ? "Yes" : "No") << "\n";
            project = project->next;
        }
    }

    void displayAllEmployees(int order)
    {
        if (order == 0)
        {
            EmployeeNode *current = head;
            while (current)
            {
                displayEmployee(current->data.employeeID);
                current = current->next;
            }
        }
        else
        {
            EmployeeNode *current = head;
            while (current && current->next)
            {
                current = current->next; 
            }
            while (current)
            {
                displayEmployee(current->data.employeeID);
                current = current->prev;
            }
        }
    }

private:
    EmployeeNode *findEmployee(const string &employeeID)
    {
        EmployeeNode *current = head;
        while (current)
        {
            if (current->data.employeeID == employeeID)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main()
{
    EmployeeList list;
    int choice;
    string employeeID, name, projectName, projectCode;
    bool isCompleted;

    do
    {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Add Project to Employee\n";
        cout << "3. Remove Employee\n";
        cout << "4. Update Employee Project\n";
        cout << "5. Display Employee\n";
        cout << "6. Display All Employees\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cout << "Enter Name: ";
            cin >> name;
            if (list.addEmployee(employeeID, name))
            {
                cout << "Employee added successfully.\n";
            }
            else
            {
                cout << "Employee ID already exists.\n";
            }
            break;
        case 2:
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cout << "Enter Project Name: ";
            cin >> projectName;
            cout << "Enter Project Code: ";
            cin >> projectCode;
            cout << "Is Completed (1 for Yes, 0 for No): ";
            cin >> isCompleted;
            if (list.addProject(employeeID, projectName, projectCode, isCompleted))
                {
                    cout << "Project added successfully.\n";
                }
            else
            {
                cout << "Employee not found or project already exists.\n";
            }
            break;
        case 3:
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            if (list.removeEmployee(employeeID))
            {
                cout << "Employee removed successfully.\n";
            }
            else
            {
                cout << "Employee not found.\n";
            }
            break;
        case 4:
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cout << "Enter New Project Name: ";
            cin >> projectName;
            cout << "Is Completed (1 for Yes, 0 for No): ";
            cin >> isCompleted;
            list.updateEmployee(employeeID, projectName, isCompleted);
            cout << "Employee project updated.\n";
            break;
        case 5:
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            list.displayEmployee(employeeID);
            break;
        case 6:
            cout << "Enter 0 for Ascending or 1 for Descending order: ";
            cin >> choice;
            list.displayAllEmployees(choice);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}