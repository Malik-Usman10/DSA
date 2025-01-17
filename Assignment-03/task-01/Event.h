#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
using namespace std;

struct Event {
    int eventID;
    string eventName;
    string startDateTime;
    int duration;

    Event* left;
    Event* right;

    Event(int id, const string& name, const string& startTime, int dur)
        : eventID(id), eventName(name), startDateTime(startTime), duration(dur), left(nullptr), right(nullptr) {}
};

#endif
