//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the Event class and the related exceptions
 */
//--------Header Guard-----------//
#ifndef BANK_EVENT_H
#define BANK_EVENT_H

//--------Header files included----//

//--------Class Prototypes--------//
class DES;

class Event{
protected:
    DES* _simPtr;
    double _time;
public:
    Event(double triggerTime, DES *simPtr);
    Event(){};
    ~Event();
    virtual void handle(); //method used to treat event, redefined in each subclass
    double getTime(); //return the time at which the event occurs (triggerTime)
};

/*class Compare
{
public:
    bool operator() (Event *a, Event *b)
    {
        return a->getTime()<b->getTime();
    }
};*/
#endif //BANK_EVENT_H
