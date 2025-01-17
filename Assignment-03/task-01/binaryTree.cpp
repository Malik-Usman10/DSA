#include "binaryTree.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear(root);
}

void BinaryTree::clear(Event* node) 
{
    if (node) 
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool BinaryTree::addEvent(int id, const string& name, const string& startTime, int duration) 
{
    Event* newEvent = new Event(id, name, startTime, duration);
    if (!root) 
    {
        root = newEvent;
        return true;
    }
    root = addEventHelper(root, newEvent);
    return true;
}

Event* BinaryTree::addEventHelper(Event* node, Event* newEvent) 
{
    if (!node) return newEvent;
    if (newEvent->startDateTime < node->startDateTime)
        node->left = addEventHelper(node->left, newEvent);
    else
        node->right = addEventHelper(node->right, newEvent);
    return node;
}

bool BinaryTree::deleteEvent(int id) 
{
    root = deleteEventHelper(root, id);
    return true;
}

Event* BinaryTree::deleteEventHelper(Event* node, int id) 
{
    if (!node) return nullptr;

    if (id < node->eventID)
        node->left = deleteEventHelper(node->left, id);
    else if (id > node->eventID)
        node->right = deleteEventHelper(node->right, id);
    else {
        if (!node->left) 
        {
            Event* temp = node->right;
            delete node;
            return temp;
        } 
        else if (!node->right)
        {
            Event* temp = node->left;
            delete node;
            return temp;
        }

        Event* temp = findMin(node->right);
        node->eventID = temp->eventID;
        node->eventName = temp->eventName;
        node->startDateTime = temp->startDateTime;
        node->duration = temp->duration;
        node->right = deleteEventHelper(node->right, temp->eventID);
    }
    return node;
}

Event* BinaryTree::findMin(Event* node) 
{
    while (node && node->left) node = node->left;
    return node;
}

void BinaryTree::printSchedule() const 
{
    inOrderTraversal(root);
}

void BinaryTree::inOrderTraversal(Event* node) const 
{
    if (node) 
    {
        inOrderTraversal(node->left);
        cout << "ID: " << node->eventID << ", Name: " << node->eventName
                  << ", Start: " << node->startDateTime << ", Duration: " << node->duration << " mins\n";
        inOrderTraversal(node->right);
    }
}

bool BinaryTree::updateEvent(int id, const string& name, const string& startTime, int duration) 
{
    deleteEvent(id);
    return addEvent(id, name, startTime, duration);
}

void BinaryTree::findOverlaps(const string& startTime, const string& endTime) const 
{
    function<void(Event*, const string&, const string&)> findOverlapsHelper = 
        [&](Event* node, const string& start, const string& end) 
        {
        if (!node) return;
        
        if (start < node->startDateTime) 
        {
            findOverlapsHelper(node->left, start, end);
        }
        
        if (node->startDateTime >= start && node->startDateTime <= end) 
        {
            cout << "Overlapping event found - ID: " << node->eventID 
                      << ", Name: " << node->eventName 
                      << ", Start: " << node->startDateTime 
                      << ", Duration: " << node->duration << " mins\n";
        }
        
        findOverlapsHelper(node->right, start, end);
    };

    findOverlapsHelper(root, startTime, endTime);
}

void BinaryTree::findFreeSlots(const string& day) const 
{
    vector<string> slots;
    freeTimeSlots(root, day, slots);
    
    if (slots.empty()) 
    {
        cout << "No free slots available for " << day << endl;
        return;
    }

    cout << "Free slots for " << day << ":\n";
    for (const auto& slot : slots) 
    {
        cout << slot << endl;
    }
}

void BinaryTree::freeTimeSlots(Event* node, const string& day, vector<string>& slots) const 
{
    if (!node) return;

    string nodeDay = node->startDateTime.substr(0, 10);
    
    if (nodeDay == day) 
    {
        freeTimeSlots(node->left, day, slots);
        
        if (!slots.empty()) 
        {
            string lastEndTime = slots.back();
            if (node->startDateTime > lastEndTime) 
            {
                slots.push_back(lastEndTime + " to " + node->startDateTime);
            }
        } 
        else 
        {
            string dayStart = day + " 00:00";
            if (node->startDateTime > dayStart) 
            {
                slots.push_back(dayStart + " to " + node->startDateTime);
            }
        }
        
        freeTimeSlots(node->right, day, slots);
    }
}

bool BinaryTree::isOverlap(const Event* node, const string& startTime, int duration) const 
{
    if (!node) return false;
    
    auto getEndTime = [](const string& start, int duration) 
    {
        int hours = stoi(start.substr(11, 2));
        int minutes = stoi(start.substr(14, 2));
        
        minutes += duration;
        hours += minutes / 60;
        minutes %= 60;
        
        string result = start.substr(0, 11);
        result += (hours < 10 ? "0" : "") + to_string(hours) + ":";
        result += (minutes < 10 ? "0" : "") + to_string(minutes);
        
        return result;
    };

    string endTime1 = getEndTime(startTime, duration);
    string endTime2 = getEndTime(node->startDateTime, node->duration);

    return (startTime < endTime2 && node->startDateTime < endTime1);
}
