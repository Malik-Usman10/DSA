#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "Event.h"
#include <vector>
#include <string>
using namespace std;

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    bool addEvent(int id, const string& name, const string& startTime, int duration);
    bool updateEvent(int id, const string& name, const string& startTime, int duration);
    bool deleteEvent(int id);
    void findOverlaps(const string& startTime, const string& endTime) const;
    void findFreeSlots(const string& day) const;
    void printSchedule() const;

private:
    Event* root;

    Event* addEventHelper(Event* node, Event* newEvent);
    Event* deleteEventHelper(Event* node, int id);
    Event* findMin(Event* node);
    bool isOverlap(const Event* node, const string& startTime, int duration) const;
    void inOrderTraversal(Event* node) const;
    void freeTimeSlots(Event* node, const string& day, vector<string>& slots) const;
    void clear(Event* node);
};

#endif 
