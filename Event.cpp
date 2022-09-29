//
// Created by redouane on 09/09/22.
//
//--------Header files included----//
#include "Event.h"
#include "Bank.h"
//--------Class Implementation--------//

/**
 * Constructor for Event class
 * @param triggerTime
 */
Event::Event(double triggerTime, Bank *simPtr) {
    _time = triggerTime;
    _simuPtr = new Bank(*simPtr);
}

/**
 * Copy constructor
 * @param e
 */
Event::Event(const Event &e) {
    _time = e._time;
    _simuPtr = e._simuPtr;
}

/**
 * Accessor to the _time field
 * @return the trigger time of the Event
 */
double Event::getTime() const {
    return _time;
}

/**
 * virtual method redefined in each subclasses
 */
void Event::handle() {}

Event::~Event() = default;

