#include "binaryTree.h"
#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "\nEvent Scheduling System\n";
    cout << "1. Add Event\n";
    cout << "2. Update Event\n";
    cout << "3. Delete Event\n";
    cout << "4. Find Overlapping Events\n";
    cout << "5. Find Free Time Slots\n";
    cout << "6. Print Full Schedule\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    BinaryTree scheduler;
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1: {  // Add Event
                int id, duration;
                string name, startTime;
                cout << "Enter Event Details:\n";
                cout << "ID: ";
                cin >> id;
                cout << "Name: ";
                clearInputBuffer();
                getline(cin, name);
                cout << "Start Date & Time (YYYY-MM-DD HH:MM): ";
                getline(cin, startTime);
                cout << "Duration (minutes): ";
                cin >> duration;

                if (scheduler.addEvent(id, name, startTime, duration)) 
                {
                    cout << "Event added successfully!\n";
                } 
                else 
                {
                    cout << "Failed to add event. Time slot might be occupied.\n";
                }
                break;
            }
            
            case 2: { 
                int id, duration;
                string name, startTime;
                cout << "Enter Event ID to update: ";
                cin >> id;
                cout << "Enter new details:\n";
                cout << "Name: ";
                clearInputBuffer();
                getline(cin, name);
                cout << "Start Date & Time (YYYY-MM-DD HH:MM): ";
                getline(cin, startTime);
                cout << "Duration (minutes): ";
                cin >> duration;

                if (scheduler.updateEvent(id, name, startTime, duration)) 
                {
                    cout << "Event updated successfully!\n";
                } 
                else 
                {
                    cout << "Failed to update event. Time slot might be occupied or event not found.\n";
                }
                break;
            }
            
            case 3: {  
                int id;
                cout << "Enter Event ID to delete: ";
                cin >> id;
                if (scheduler.deleteEvent(id)) 
                {
                    cout << "Event deleted successfully!\n";
                } 
                else 
                {
                    cout << "Event not found!\n";
                }
                break;
            }
            
            case 4: {  
                string startTime, endTime;
                cout << "Enter time range to check for overlaps:\n";
                cout << "Start Date & Time (YYYY-MM-DD HH:MM): ";
                getline(cin, startTime);
                cout << "End Date & Time (YYYY-MM-DD HH:MM): ";
                getline(cin, endTime);
                
                cout << "\nOverlapping Events:\n";
                scheduler.findOverlaps(startTime, endTime);
                break;
            }
            
            case 5: { 
                string date;
                cout << "Enter date to find free slots (YYYY-MM-DD): ";
                getline(cin, date);
                scheduler.findFreeSlots(date);
                break;
            }
            
            case 6: { 
                cout << "\nFull Schedule:\n";
                scheduler.printSchedule();
                break;
            }
            
            case 7: {
                cout << "Thank you for using the Event Scheduling System!\n";
                return 0;
            }
            
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
