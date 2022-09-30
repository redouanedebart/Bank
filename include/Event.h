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
class Bank;

class Event{
protected:
    Bank* _simuPtr; //pointer to the bank
    double _time; //trigger time of the event
public:
    Event(double triggerTime, Bank *simPtr);
    Event(const Event& e);
    Event()= default;;
    ~Event();
    virtual void handle(); //method used to treat event, redefined in each subclass
    double getTime() const; //return the time at which the event occurs (triggerTime)
    bool operator<(const Event* &rhs);
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
