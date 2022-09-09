//
// Created by redouane on 08/09/22.
//
/*
 * Header file for the Event class and the related exceptions
 */
//--------Header Guard-----------//
#ifndef BANK_EVENT_H
#define BANK_EVENT_H

//--------Class Prototypes--------//
class Event{
protected:
    double _time;
public:
    Event();
    ~Event();
    virtual void handle(); //method used to treat event, redefined in each subclass
    double getTime(); //return the time at which the event occurs
};
#endif //BANK_EVENT_H
