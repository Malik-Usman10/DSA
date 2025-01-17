#include <iostream>
#include <string>

using namespace std;

struct Patient
{
    int patientID;
    string name;
    int severity;
    Patient *next;

    Patient(int id, const string &name, int severity)
        : patientID(id), name(name), severity(severity), next(nullptr) {}
};

class PatientQueue
{
private:
    Patient *head;

public:
    PatientQueue() : head(nullptr) {}

    bool isDuplicate(int id, const string &name)
    {
        Patient *current = head;
        while (current)
        {
            if (current->patientID == id)
            {
                cout << "Error: Patient with ID " << id << " already exists in the queue.\n";
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool enqueuePatient(int id, const string &name, int severity)
    {
        if (isDuplicate(id, name))  
        {
            return false;  
        }

        Patient *newPatient = new Patient(id, name, severity);

        if (!head || head->severity < severity)
        {
            newPatient->next = head;
            head = newPatient;
        }
        else
        {
            Patient *current = head;
            while (current->next && current->next->severity >= severity)
            {
                current = current->next;
            }
            newPatient->next = current->next;
            current->next = newPatient;
        }

        cout << "Patient with ID " << id << " added to the queue.\n";
        return true; 
    }

    void servePatient()
    {
        if (!head)
        {
            cout << "The queue is empty, no patients to serve.\n";
            return;
        }

        Patient *patientToServe = head;
        head = head->next;

        cout << "Serving Patient ID: " << patientToServe->patientID << "\n";
        cout << "Name: " << patientToServe->name << "\n";
        cout << "Severity Level: " << patientToServe->severity << "\n";

        delete patientToServe;
    }

    void viewPatients()
    {
        if (!head)
        {
            cout << "The queue is empty.\n";
            return;
        }

        Patient *current = head;
        cout << "Patients in Queue:\n";
        cout << "ID\tName\tSeverity\n";
        while (current)
        {
            cout << current->patientID << "\t" << current->name << "\t" << current->severity << "\n";
            current = current->next;
        }
    }

    ~PatientQueue()
    {
        while (head)
        {
            servePatient();
        }
    }
};

int main()
{
    PatientQueue queue;

    int choice;
    do
    {
        cout << "\nHospital Patient Management System\n";
        cout << "1. Enqueue Patient\n";
        cout << "2. Serve Patient\n";
        cout << "3. View Patients in Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, severity;
            string name;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Severity Level (1-10): ";
            cin >> severity;

            if (!queue.enqueuePatient(id, name, severity))
            {
                cout << "Please try again with a unique ID and name.\n";
            }
        }
        else if (choice == 2)
        {
            queue.servePatient();
        }
        else if (choice == 3)
        {
            queue.viewPatients();
        }
        else if (choice != 4)
        {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    cout << "Exiting the system. Goodbye!\n";
    return 0;
}